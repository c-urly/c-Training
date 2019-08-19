#include <iostream>
namespace oslib{
class TCB
{
	private:
		TCB();
		TCB(const TCB &t); // copy constructor
		TCB& operator=(const TCB&);
		int taskId;
		int priority;
		std::string tname;
		std::string taskStatus;
		static int count;

	public:


		TCB(const TCB&, std::string, int, std::string);
		TCB(std::string ,int);


		int getTaskid() const;
		void setTaskStatus(std::string);
		std::string getTaskStatus() const;
		int getTaskCount() const;
		void taskInfo();
		static int showTaskCount(){
			return count;
		}
		
		
};

int TCB::count = 0;

	TCB::TCB(std::string tname, int priority): tname(tname) ,priority(priority){
		this->taskId = count;
		setTaskStatus("ready");
		count++;
	}
	
	int TCB::getTaskid() const{
		return taskId;
	}

	void TCB::setTaskStatus(std::string status){
		this->taskStatus = status;
	}
	std::string TCB::getTaskStatus() const{
		return tname;
	}
	TCB::TCB(const TCB &otask, std::string tname, int priority, std::string status){
		this->tname = tname;
		this->priority = priority;
		this->taskStatus = status;
	}
	void TCB::taskInfo(){
		std::cout << "Task Id: "<<taskId<<"\n"<<"Task Name: " << tname <<"\n"<< "Priority: "<<priority<<"\n"<<"Task Status: "<<taskStatus<<"\n";
	}
	int TCB::getTaskCount() const {
		return count;
	}
	
		
}


using namespace oslib;

void demo_task()
{

#if 1
	// TCB t; // should not be allowed
	TCB osensortask("Sensor Task",128 ); // name and priortiy
	TCB *ologgerTask = new TCB("Logger Task", 100);

	osensortask.getTaskid(); //should have a unique task id
	ologgerTask->getTaskid(); //should have a unique task id

	ologgerTask->setTaskStatus("suspended");
	osensortask.getTaskStatus(); // default: ready
#endif
#if 1
	osensortask.taskInfo(); // Shall display all attributes of class
	ologgerTask->taskInfo();
	// osensortask = *ologgerTask; // should not be allowed.

	// TCB temp(osensortask); // should not be allowed
#endif
#if 1
	TCB xtemp(osensortask,"copy of Sensor" ,150, "suspended"); // name, priority and status, task_id should be unique.

	xtemp.getTaskCount();

	TCB::showTaskCount(); // static method.
#endif
}

int main()
{
	demo_task();

}