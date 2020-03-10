#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include  <vector>
#include "Memento.h"
class Container
{
private:
     vector<unique_ptr<IShape>> container;
     IShape* controlled;
public:
     void Insert(IShape* toAdd)
    {
         this->container.push_back(unique_ptr<IShape>(toAdd));
    }
     void changeControlller() {
         vector<unique_ptr<IShape>>::iterator it;
        for (it = container.begin(); it->get() != controlled; it++)
        {
            vector<unique_ptr<IShape>>::iterator tmp;
            tmp = it;
            if ((++tmp) == container.end())
            {
                it = container.begin();
            }
        }
        ++it;
        if (it == container.end())
            controlled = container.begin()->get();
        else
            controlled = it->get();
    }
     IShape& getControlled()
    {
        return *controlled;
    }
	void checkCollision()
     {
        vector<unique_ptr<IShape>>::iterator it;
        vector<unique_ptr<IShape>>::iterator itref;
        itref = container.begin();
        for (it = container.begin(); it != container.end(); it++)
        {
            if(it != itref && itref->get()->CheckCollision(*it->get()))
            {
                itref->get()->sizeIncrease();
                it->get()->sizeIncrease();
            }
        }
     }
    void initControlled(IShape* base)
    {
        controlled = base;
        Insert(base);
        controlled = base;
    }
    void addChildToControlled(IShape* toAdd)
    {
        controlled->addChild(toAdd);
    }
    void mainEvs()
    {
        vector<unique_ptr<IShape>>::iterator it;
        for (it = container.begin(); it != container.end(); it++)
        {
            it->get()->IDraw();
        }
    }
    void groupShapes() {
        vector<unique_ptr<IShape>>::iterator it;
        Composite* newComp = new Composite();
        for (it = container.begin(); it != container.end(); it++)
        {   
                IShape* temp = it->get()->IClone();
                newComp->addChild(temp);       
        }
        container.clear();
        initControlled(newComp);
    }
};
class Controller
{
private:
    static Container cont;
public:
    static void initControlled(IShape* base)
    {
        cont.initControlled(base);
    }
	static void CheckCollision()
    {
        cont.checkCollision();
    }
	static void changedControlled()
    {
        cont.changeControlller();
    }
	static void addChildToControlled(IShape* toAdd)
    {
        cont.addChildToControlled(toAdd);
    }
	static void addShape(IShape* toAdd)
    {
        cont.Insert(toAdd);
    }
	static void Process()
    {
        cont.mainEvs();
    }
	static void Group()
    {
        cont.groupShapes();
    }
	static void displayMenu()
    {
        cout << "Press 1 to add rectangle child" << endl;
        cout << "Press 2 to add circle child" << endl;
        cout << "Press 3 to change controlled Shape" << endl;
        cout << "Press 4 to add Shape to scene" << endl;
        cout << "Press 5 to change tail" << endl;
        cout << "Press 6 to group objects" << endl;
        cout << "Press 7 to save state" << endl;
        cout << "Press 8 to load state" << endl;
    }
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        IShape& temp = cont.getControlled();
        if (action == GLFW_RELEASE) {
            if (key == GLFW_KEY_1)
            {
                addChildToControlled(new Rectangle("fast"));
            }
            if (key == GLFW_KEY_2)
            {
                addChildToControlled(new Circle("fast"));
            }
            if (key == GLFW_KEY_3)
            {
                changedControlled();
            }
            if (key == GLFW_KEY_4)
            {
                addShape(new Rectangle("fast"));
            }
            if (key == GLFW_KEY_5)
            {
                cont.getControlled().changeTail();
            }
            if (key == GLFW_KEY_6)
            {
                Group();
            }
            if (key == GLFW_KEY_7)
            {
                ShapeMemento::saveState(cont.getControlled());
            }
            if (key == GLFW_KEY_8)
            {
                ShapeMemento::loadState(cont.getControlled());
            }         
        }
    	if(action == GLFW_REPEAT)
    	{
            if (key == GLFW_KEY_W)
            {
                temp.moveUp();
            }
            if (key == GLFW_KEY_S)
            {
                temp.moveDown();
            }
            if (key == GLFW_KEY_A)
            {
                temp.moveLeft();
            }
            if (key == GLFW_KEY_D)
            {
                temp.moveRight();
            }
    	}
    }
};
Container Controller::cont;