#include "Solutions.h"
#include <ctime>
#include <cstdlib>


Solutions::Solutions()
{
    for (int i = 0; i < (Constance::n_operations/2 + Constance::n_maintenance); i++ )
    {
        machine_one[i] = nullptr;
        machine_two[i] = nullptr;
    }
	machine_one_operations_number = 0;
	machine_two_operations_number = 0;
}
Solutions::~Solutions()
{
}
Operation** Solutions::get_machine_one()
{
    return machine_one;
}
Operation** Solutions::get_machine_two()
{
    return machine_two;
}

void Solutions::insert_operation(int machine_number, Operation * operation, int insert_time)
{
	int i = 0;
	if (machine_number == 1)
	{
		if (machine_one_operations_number == 0)
		{
			operation->set_start(0);
		}
		else
		{
			while (i < machine_one_operations_number - 1
				&& (i < Constance::n_tasks + Constance::n_maintenance - 1)
				&& ((machine_one[i + 1]->get_start() - (machine_one[i]->get_start() + machine_one[i]->get_duration())) < operation->get_duration())
				&& (machine_one[i]->get_start() + machine_one[i]->get_duration() < insert_time))
			{
				i++;
			}
			operation->set_start(machine_one[i]->get_start() + machine_one[i]->get_duration());
		}
		if (machine_one_operations_number < Constance::n_tasks + Constance::n_maintenance)
		{
			machine_one[machine_one_operations_number] = operation;
			machine_one_operations_number++;
			this->insertion_sort_machine_one(machine_one_operations_number);
		}
	}

	else if (machine_number == 2)
	{
		while (i < Constance::n_tasks + Constance::n_maintenance && machine_two[i] != nullptr)
			i++;
		machine_two[i] = operation;
		this->insertion_sort_machine_two(i + 1);
	}
}

void Solutions::insertion_sort_machine_one(int operations_on_machine)
{
	int j;
	Operation* pom;
	for (int i = 1; i < operations_on_machine; i++)
	{
		j = i - 1;
		while ((j >= 0) && (this->get_machine_one()[j + 1]->get_start() < this->get_machine_one()[j]->get_start()))
		{
			pom = this->get_machine_one()[j + 1];
			this->get_machine_one()[j + 1] = this->get_machine_one()[j];
			this->get_machine_one()[j] = pom;
			j--;
		}
	}
}

void Solutions::insertion_sort_machine_two(int operations_on_machine)
{
	int j;
	Operation* pom;
	for (int i = 1; i < operations_on_machine; i++)
	{
		j = i - 1;
		while ((j >= 0) && (this->get_machine_two()[j + 1]->get_start() < this->get_machine_two()[j]->get_start()))
		{
			pom = this->get_machine_two()[j + 1];
			this->get_machine_two()[j + 1] = this->get_machine_two()[j];
			this->get_machine_two()[j] = pom;
			j--;
		}
	}
}
