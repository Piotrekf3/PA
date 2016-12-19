#pragma once
#include "Operation.h"
#include"Constance.h"
class Solutions
{
    private:
		int machine_one_operations_number;
		int machine_two_operations_number;
        Operation *machine_one[Constance::n_operations/2 + Constance::n_maintenance];
		Operation *machine_two[Constance::n_operations/2 + Constance::n_maintenance];
    public:
        Solutions();
        ~Solutions();
		void insertion_sort_machine_one(int operations_on_machine);
		void insertion_sort_machine_two(int operations_on_machine);
		void insert_operation(int machine_number, Operation * operation,int insert_time=0); //wstawia w pierwsze wolne miejsce, 
		//jako insert time poda� ready time
        Operation** get_machine_one();
        Operation** get_machine_two();
};
