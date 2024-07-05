#pragma once
#include <array>
#include <bitset>
#include <memory.h>
#include <vector>

class Manager;
class Entity;
class System;
class Component;

using componentID = std::size_t;
using systemID = std::size_t;

constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxSystems = 32;

using componentBitSet = std::bitset<maxComponents>;
using systemBitSet = std::bitset<maxSystems>;

using componentArray = std::array<Component *, maxComponents>;
using systemArray = std::array<System *, maxSystems>;

inline componentID getComponentID() {
    static componentID lastID = 0;
    return lastID++;
}

inline systemID getSystemID() {
    static systemID lastID = 0;
    return lastID++;
}

template <typename T> inline componentID getComponentID() {
    static componentID componentID = getComponentID();
    return componentID;
}

template <typename T> inline systemID getSystemID() {
    static systemID systemID = getSystemID();
    return systemID;
}

class Component {
public:
    Entity *entity;

    virtual void init(){};
    virtual void update(){};
    virtual void draw(){};
};

class System {
public:
    virtual void init(){};
    virtual void update(){};
};

class Entity {
public:
    Manager *manager;

    std::vector<std::unique_ptr<Component>> components;
    componentArray componentArray;
    componentBitSet componentBitSet;

    void init() {
        for (auto &c : components) {
            c->init();
        }
    };
    void update() {
        for (auto &c : components) {
            c->update();
        }
    };
    void draw() {
        for (auto &c : components) {
            c->draw();
        }
    };
    template <typename T, typename... TArgs>
    T& addComponent(TArgs&& ...mArgs){
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<T> uPtr{c};
        components.emplace_back(c);
        componentArray[getComponentID<T>()] = c;
        componentBitSet[getComponentID<T>()] = true;
        return *c;
    }
    template<typename T>
    T& getComponent(){
        return static_cast<T*>(componentArray[getComponentID<T>()]);
    }
    template<typename T>
    bool hasComponent(){
        return componentBitSet[getComponentID<T>()];
    }
};

class Manager {
    std::vector<std::unique_ptr<Entity>> entities;

    void init() {
        for (auto &e : entities) {
            e->init();
        }
    };
    void update() {
        for (auto &e : entities) {
            e->update();
        }
    };
    void draw() {
        for (auto &e : entities) {
            e->draw();
        }
    };
    Entity &addEntity(Entity &e) {

        // entities.emplace_back(e);

        return e;
  }
};
