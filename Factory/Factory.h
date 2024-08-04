#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include <string>
#include <iostream>

//抽象的加工策略接口
class ProcessingStrategy {
public:
    virtual ~ProcessingStrategy(){}
    virtual void process() = 0;
};

//具体的加工策略类
class HeatingStrategy : public ProcessingStrategy {
public:
    void process() override;
};

class CoolingStrategy : public ProcessingStrategy {
public:
    void process() override;
};

class MixingStrategy : public ProcessingStrategy {
public:
    void process() override;
};

//策略工厂类
class StrategyFactory {
public:
    static std::unique_ptr<ProcessingStrategy> createStrategy(const std::string type);
};

//抽象的产品类
class Product {
public:
    virtual ~Product(){}
    virtual std::string getName()const = 0;
    virtual void process();
    void setStrategy(std::unique_ptr<ProcessingStrategy> strategy);
protected:
    std::unique_ptr<ProcessingStrategy> strategy;
};

//具体的产品子类
class ProductA : public Product {
public:
    std::string getName() const override;
};

class ProductB : public Product {
public:
    std::string getName() const override;
};

class ProductC : public Product {
public:
    std::string getName() const override;
};

//工厂类，用于创建产品对象
class ProductFactory {
public:
    static std::unique_ptr<Product> createProduct(const std::string& type);
};

//单例模式实现工厂管理者类
class FactoryManager {
public:
    static FactoryManager& getInstance();
    std::unique_ptr<Product> createProduct(const std::string& type);
    void assignStrategy(Product* product,const std::string& strategyType);
private:
    FactoryManager(){}
    FactoryManager(const FactoryManager&) = delete;
    FactoryManager& operator=(const FactoryManager&) = delete;
};

#endif // FACTORY_H
