<?php

//MVC 模式代表 Model-View-Controller（模型-视图-控制器） 模式。这种模式用于应用程序的分层开发。

//Model（模型） - 模型代表一个存取数据的对象或 JAVA POJO。它也可以带有逻辑，在数据变化时更新控制器。
//View（视图） - 视图代表模型包含的数据的可视化。
//Controller（控制器） - 控制器作用于模型和视图上。它控制数据流向模型对象，并在数据变化时更新视图。它使视图与模型分离开。

//我们将创建一个作为模型的 Student 对象。
//StudentView 是一个把学生详细信息输出到控制台的视图类，StudentController 是负责存储数据到 Student 对象中的控制器类，并相应地更新视图 StudentView。

//Model层
class Student {
    private $rollNo;
    private $name;

    public function getRollNo() {
        return $this->rollNo;
    }

    public function setRollNo($value) {
        $this->rollNo = $value;
    }

    public function getName() {
        return $this->name;
    }

    public function setName($value) {
        $this->name = $value;
    }
}

//view层
class StudentView {
    public function printStudentDetail($studentName, $studentRollNo) {
        echo 'student: ' . PHP_EOL;
        echo 'Name: ' . $studentName . PHP_EOL;
        echo 'Roll No: ' . $studentRollNo . PHP_EOL;
    }
}

//Controller层
class StudentController {
    private $model;
    private $view;

    public function __construct($model, $view)
    {
        $this->model = $model;
        $this->view  = $view;
    }

    public function setStudentName($studentName) {
        $this->model->setName($studentName);
    }

    public function getStudentName() {
        $this->model->getName();
    }

    public function setStudentRollNo($studentRollNo) {
        $this->model->setRollNo($studentRollNo);
    }

    public function getStudentRollNo() {
        $this->model->getRollNo();
    }

    public function updateView() {
        $this->view->printStudentDetail($this->model->getName(), $this->model->getRollNo());
    }
}


function retrieveStudentFromDatabase() {
    $student = new Student();
    $student->setName('Robert');
    $student->setRollNo('10');
    return $student;
}

//从数据获取学生记录
$model = retrieveStudentFromDatabase();

//创建一个视图：把学生详细信息输出到控制台
$view = new StudentView();

$controller = new StudentController($model, $view);
$controller->updateView();

//更新数据模型
$controller->setStudentName('John');
$controller->updateView();
