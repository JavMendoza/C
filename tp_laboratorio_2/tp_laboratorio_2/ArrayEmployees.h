#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief  To indicate that all position in the array are empty
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param list Employee array of eEmployee type
 * \param len int Array length
 *
 */
void initEmployees(eEmployee listE[], int len);

/** \brief Hardcoding Employees inside the Employee array
 *
 * \param list Employee array of eEmployee type
 * \param len int Array length
 * \param qty int amount of hardcoded employees
 * \return counter int which is the number of employees that were correctly added
 *
 */
int hardcodeEmployees(eEmployee listE[], int len, int qty);

/** \brief Looks for an empty employee to use
 *
 * \param list Employee array of eEmployee type
 * \param len int Array length
 * \return index int which is the index of the array list
 *
 */
int searchFreeSpot(eEmployee listE[], int len);

/** \brief Add employee to the array list
 *
 * \param list Employee array of eEmployee type
 * \param len int Array length
 * \param idEmployee int id of the employee to be used
 * \return ok int which is an indicator 1 - everything was good / 0 - there was problem
 *
 */
int addEmployee(eEmployee listE[], int len, int idEmployee);

/** \brief Creates a new Employee struct
 *
 * \param idEmployee int
 * \param name[] char
 * \param lastname[] char
 * \param salary float
 * \param sector int
 * \return eEmployee
 *
 */
eEmployee newEmployee(int idEmployee,char name[],char lastname[], float salary, int sector);

/** \brief Given an Id checks if there is an Employee with that ID
 *
 * \param idEmployee int
 * \param list Employee array of eEmployee type
 * \param len int Array length
 * \return index int which is the index of the employee if found or -1 if not
 *
 */
int findEmployeeById(int idEmployee, eEmployee listE[], int len);

/** \brief Remove employee from the array list
 *
 * \param list Employee array of eEmployee type
 * \param len int Array length
 * \return ok int which is an indicator 1 - everything was good / 0 - there was problem
 *
 */
int removeEmployee(eEmployee listE[], int len);

/** \brief Update employee from the array list
 *
 * \param list Employee array of eEmployee type
 * \param len int Array length
 * \return ok int which is an indicator 1 - everything was good / 0 - there was problem
 *
 */
int updateEmployee(eEmployee listE[], int len);

/** \brief Prints the data of one Employee
 *
 * \param eEmployee
 */
void printEmployee(eEmployee x);

/** \brief Prints the data of every Employee in the system
 *
 * \param list Employee array of eEmployee type
 * \param len int Array length
 */
void printEmployees(eEmployee listE[], int len);

/** \brief Sort employees in the system by Sector and last name
 *
 * \param list Employee array of eEmployee type
 * \param len int Array length
 * \param order int 1 - ASC / 0 - DESC
 */
void sortEmployees(eEmployee listE[], int len, int order);

/** \brief Report Salaries showing total salaries and average of all employees
 *          and the amount of employees that earn more than the average salary
 *
 * \param list Employee array of eEmployee type
 * \param len int Array length
 */
void reportSalaries(eEmployee listE[], int len);

/** \brief Checks if the Employee List is empty or not
 *
 * \param list Employee array of eEmployee type
 * \param len int Array length
 * \return index int which is the index of the employee or -1 if not found any employees
 */
int employeesIsEmpty(eEmployee listE[], int len);
