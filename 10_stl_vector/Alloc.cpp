#include "Alloc.h"

namespace TinySTL {
	char* alloc::start_free = 0;
	char* alloc::end_free = 0;
	size_t alloc::heap_size = 0;

	alloc::obj* alloc::free_list[alloc::ENFreeLists::NFREELISTS] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	// �����ڴ�
	void* alloc::allocate(size_t bytes) {
		if (bytes > EMaxBytes::MAXBYTES) {
			return malloc(bytes);
		}
		// ��õ�ǰ����
		size_t index = FREELIST_INDEX(bytes);
		obj* list = free_list[index];
		if (list) {
			// list�����ڿռ�
			free_list[index] = list->next;
			return list;
		}
		else {
			// listû���㹻�ռ�
			return refill(ROUND_UP(bytes));
		}
	}

	// �����ڴ�
	void alloc::deallocate(void* ptr, size_t bytes) {
		if (bytes > EMaxBytes::MAXBYTES) {
			// �ڴ泬����ֱ�ӻ���
			free(ptr);
		}
		else {
			size_t index = FREELIST_INDEX(bytes);
			obj* node = static_cast<obj*>(ptr);
		}
	}

	// ���·���
	void* alloc::reallocate(void* ptr, size_t old_sz, size_t new_sz) {
		deallocate(ptr, old_sz);
		ptr = allocate(new_sz);

		return ptr;
	}

	// �����ڴ�
	void* alloc::refill(size_t bytes) {
		// ÿ�����ӵĽڵ���
		size_t nobjs = ENObjs::NOBJS;
		char* chunk = chunk_alloc(bytes, nobjs);
		obj** my_free_list = 0;
		obj* result = 0;
		obj* current_obj = 0, *next_obj = 0;

		if (nobjs == 1) {
			// ֻ��һ������
			return chunk;
		}
		else {
			my_free_list = free_list + FREELIST_INDEX(bytes);
			result = (obj*)(chunk);
			*my_free_list = next_obj = (obj*)(chunk + bytes);
			for (int i = 1;; ++i) {
				current_obj = next_obj;
				next_obj = (obj*)((char*)next_obj + bytes);
				if (nobjs - 1 == i) {
					current_obj->next = 0;
					break;
				}
				else {
					current_obj->next = next_obj;
				}
			}

			return result;
		}
	}

	// �����ڴ�����
	char* alloc::chunk_alloc(size_t bytes, size_t& nobjs) {
		char* result = 0;
		size_t total_bytes = bytes * nobjs;
		size_t bytes_left = end_free - start_free;

		// �ڴ��ʣ��ռ���ȫ����
		if (bytes_left >= total_bytes) {
			result = start_free;
			start_free = start_free + total_bytes;
			return result;
		}
		else if (bytes_left >= bytes) { // ����1�����߶�� 
			nobjs = bytes_left / bytes;
			total_bytes = nobjs * bytes;
			result = start_free;
			start_free += total_bytes;
			return result;
		}
		else{ // �ڴ����һ�鶼�޷��ṩ
			// ��Ҫmalloc���ڴ���
			// ROUND_UP(heap_size >> 4) ��һ��׷�������������ΪԽҪԽ��
			size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);
			// �Ȱ�ʣ����ڴ����ȥ
			if (bytes_left > 0) {
				obj** my_free_list = free_list + FREELIST_INDEX(bytes_left);
				((obj*)start_free)->next = *my_free_list;
				*my_free_list = (obj*)start_free;
			}
			start_free = (char*)malloc(bytes_to_get);
			// û�з���ɹ�
			if (!start_free) {
				obj** my_free_list = 0, * p = 0;
				for (int i = 0; i < EMaxBytes::MAXBYTES; i += EAlign::ALIGN) {
					my_free_list = free_list + FREELIST_INDEX(i);
					p = *my_free_list;
					if (0 != p) {
						*my_free_list = p->next;
						start_free = (char*)p;
						end_free = start_free + i;
						return chunk_alloc(bytes, nobjs);
					}
				}
				end_free = 0;
			}

			// ����ɹ�
			heap_size += bytes_to_get;
			end_free = start_free + bytes_to_get;
			return chunk_alloc(bytes, nobjs);
		}
	}
}