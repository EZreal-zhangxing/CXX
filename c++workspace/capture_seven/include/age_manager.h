#ifndef AGE_MANAGER
#define AGE_MANAGER

class age_manager{
public:
    age_manager() = default;
    Student & modify_age(Student & stud){
        /**
         *  修改的是student类的私有变量，如果不申明为student的友元类型则会导致无法访问
         *  raise 编译错误
        */
        std::cout << " name :" << stud.student_name << " age + 1" << std::endl;
        stud.age += 1; 
        return stud;
    }

    Student & modify_name(Student & stud){
        stud.student_name += "_";
        return stud;
    }
};

#endif