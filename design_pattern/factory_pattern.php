<?php

//工厂模式(Factory Pattern)
//最常用的设计模式之一. 这种类型的设计模式属于创建型模式,　它提供了一种创建对象的最佳方式.
//在工厂模式中,我们在创建对象时不会对客户端暴露创建逻辑,并且是通过使用一个共同的接口来指向新创建的对象.

//介绍
//意图：定义一个创建对象的接口，让其子类自己决定实例化哪一个工厂类，工厂模式使其创建过程延迟到子类进行。
//主要解决：主要解决接口选择的问题。
//何时使用：我们明确地计划不同条件下创建不同实例时。
//如何解决：让其子类实现工厂接口，返回的也是一个抽象的产品。
//关键代码：创建过程在其子类执行

//优点：
// 1、一个调用者想创建一个对象，只要知道其名称就可以了。
// 2、扩展性高，如果想增加一个产品，只要扩展一个工厂类就可以。
// 3、屏蔽产品的具体实现，调用者只关心产品的接口。

//缺点：
//每次增加一个产品时，都需要增加一个具体类和对象实现工厂，使得系统中类的个数成倍增加，在一定程度上增加了系统的复杂度，同时也增加了系统具体类的依赖。

//注意事项：
//作为一种创建类模式，在任何需要生成复杂对象的地方，都可以使用工厂方法模式。
//有一点需要注意的地方就是复杂对象适合使用工厂模式，而简单对象，特别是只需要通过 new 就可以完成创建的对象，无需使用工厂模式。
//如果使用工厂模式，就需要引入一个工厂类，会增加系统的复杂度。

//［事例程序］
//我们将创建一个 Shape 接口和实现 Shape 接口的实体类。下一步是定义工厂类 ShapeFactory。
interface ShapeLy {
    public function draw();
}

class Rectangle implements ShapeLy {
    public function draw()
    {
        // TODO: Implement draw() method.
        echo 'Inside Rectangle::draw() method' . PHP_EOL;
    }
}

class Square implements ShapeLy {
    public function draw()
    {
        // TODO: Implement draw() method.
        echo 'Inside Square::draw() method' . PHP_EOL;
    }
}

class Circle implements ShapeLy {
    public function draw()
    {
        // TODO: Implement draw() method.
        echo 'Inside Circle::draw() method' . PHP_EOL;
    }
}

class ShapeFactory {
    public function getShape ($shapeType) {
        if (empty($shapeType)) {
            return null;
        }
        if ('CIRCLE' == $shapeType) {
            return new Circle();
        }
        if ('RECTANGLE' == $shapeType) {
            return new Rectangle();
        }
        if ('SQUARE' == $shapeType) {
            return new Square();
        }
        return null;
    }
}

$shapeFactory = new ShapeFactory();
$shape1 = $shapeFactory->getShape('CIRCLE');
$shape1->draw();
$shape2 = $shapeFactory->getShape('RECTANGLE');
$shape2->draw();
$shape3 = $shapeFactory->getShape('SQUARE');
$shape3->draw();


















