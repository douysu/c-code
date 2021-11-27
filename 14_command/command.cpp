#include <iostream>

using namespace std;

class Televation
{
private:
    /* data */
public:
    Televation() {}
    virtual ~Televation() {}

    void action()
    {
        cout << "Televation action" << endl;
    }
};

class Command
{
public:
    virtual ~Command() {}
    virtual void execute() const = 0;
};

class TvOpenCommand : public Command
{
public:
    TvOpenCommand(Televation* televation)
    {
        m_televation = televation;
    }

    virtual ~TvOpenCommand() {}

    void execute() const override
    {
        cout << "TVopen::execute"  << endl;
	    m_televation->action();
    }
private:
    Televation* m_televation;
};

class Controller
{
public:
    Controller(Command* command)
    {
        m_command = command;
    }

    virtual ~Controller()
    {

    }

    void call()
    {
        cout << "Controller calling" << endl;
        m_command->execute();
    }

private:
    Command* m_command;
};

// int main()
// {
//     // Invoker Controller
//     // Receiver Televation
//     Televation* televation = new Televation();
//     TvOpenCommand* openCommand = new TvOpenCommand(televation);
//     Controller* controller = new Controller(openCommand);
//     controller->call();


//     /**
//     Receiver* receiver = new Receiver();
//     TvOpenCommand* openCommand = new TvOpenCommand(receiver);
//     Invoker* invoker = new Invoker(openCommand);
//     invoker->call();
//     */ 

//     delete controller;
//     delete openCommand;
//     delete televation;
//     return 0;
// }