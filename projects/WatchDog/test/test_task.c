
#include "test_macros.h"

#include "task.h"
#include "ilrd_uid.h"	/* UID */

static int AddFunc(void* params)
{
	((int*)(params))[2] = ((int*)(params))[0] + ((int*)(params))[1];
	return 0;
}

static int DiffFunc(void* params)
{
	((int*)(params))[2] = ((int*)(params))[0] - ((int*)(params))[1];
	return 0;
}

static int EqualFunc(void* params)
{
	return !(((int*)(params))[0] == ((int*)(params))[1]);
}


void TestTask()
{
	int nums[3] = {1, 2, 0};
	int nums_eq[2];
	int n = 0;
	task_t* task_add = TaskCreate(AddFunc, &nums, 0);
	task_t* task_diff = TaskCreate(DiffFunc, &nums, 0);
	task_t* task_equal = TaskCreate(EqualFunc, &nums_eq, 0);
	task_t* task_extra = NULL;
	
	TEST("Created Task", !!task_add, !NULL);
	
	TaskRun(task_add);
	n = nums[2];
	nums_eq[0] = n;
	nums_eq[1] = 3;
	TEST("Add task, is equal", TaskRun(task_equal), 0);
	nums_eq[1] = 1;
	TEST("Add task, is not equal", TaskRun(task_equal), 1);
	
	task_extra = TaskCreate(AddFunc, &nums, 0);
	
	TEST("Tasks with same func are different", 
									TaskIsEqual(task_add, task_extra), 0);
	TEST("Same Tasks", TaskIsEqual(task_add, task_add), 1);
	TEST("Task is differnt from NULL", TaskIsEqual(task_add, NULL), 0);
	
	nums[0] = 3;
	nums[1] = 1;
	TaskRun(task_diff);
	n = nums[2];
	nums_eq[0] = n;
	nums_eq[1] = 2;
	TEST("Diff task", TaskRun(task_equal), 0);
	
	TaskDestroy(task_add);
	TaskDestroy(task_diff);
	
	task_add = TaskCreate(AddFunc, &nums, 0);
	task_diff = TaskCreate(DiffFunc, &nums, 8);
	TEST("Different time to run", 
			(TaskGetTimeToRun(task_add)) == (TaskGetTimeToRun(task_diff)), 0);
	TaskSetTimeToRun(task_add);
	TEST("Same time to run", 
			(TaskGetTimeToRun(task_add)) == (TaskGetTimeToRun(task_diff)), 0);
	
	TaskDestroy(task_add);
	TaskDestroy(task_diff);
	TaskDestroy(task_equal);
	TaskDestroy(task_extra);
}


int main(void)
{
	TestTask();
	PASS;
	return 0;
}
