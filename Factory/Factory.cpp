#include "Factory.h"

//具体的加工策略类实现
void HeatingStrategy::process() {
    std::cout<<"Processing with Heating Strategy.\n";
}
void CoolingStrategy::process() {
    std::cout<<"Processing with Cooling Strategy.\n";
}
void MixingStrategy::process() {
    std::cout<<"Processing with Mixing Strategy.\n";
}

//策略工厂类实现
std::unique_ptr<ProcessingStrategy> StrategyFactory::createStrategy(const std::string type) {
    if (type=="Heating") {
        return std::make_unique<HeatingStrategy>();
    }
    else if (type=="Cooling") {
        return std::make_unique<CoolingStrategy>();
    }
    else if (type=="Mixing") {
        return std::make_unique<MixingStrategy>();
    }
    else {
        return nullptr;
    }
}

//抽象的产品类实现
void Product::process() {
    if (strategy) {
        strategy->process();
    }
    else {
        std::cout<<getName()<<" has no processing strategy assigned.\n";
    }
}

void Product::setStrategy(std::unique_ptr<ProcessingStrategy> strategy) {
    this->strategy = std::move(strategy);
}

//具体的产品子类实现
std::string ProductA::getName() const {
    return "ProductA";
}

std::string ProductB::getName() const {
    return "ProductB";
}

std::string ProductC::getName() const {
    return "ProductC";
}

//工厂类实现
std::unique_ptr<Product> ProductFactory::createProduct(const std::string &type) {
    if (type=="ProductA") {
        return std::make_unique<ProductA>();
    }
    else if (type=="ProductB") {
        return std::make_unique<ProductB>();
    }
    else if (type=="ProductC") {
        return std::make_unique<ProductC>();
    }
    else {
        return nullptr;
    }

}

//单例模式实现工厂管理者类实现
FactoryManager &FactoryManager::getInstance() {
    static FactoryManager instance;
    return instance;
}

std::unique_ptr<Product> FactoryManager::createProduct(const std::string& type) {
    return ProductFactory::createProduct(type);
}

void FactoryManager::assignStrategy(Product *product, const std::string &strategyType) {
    auto strategy = StrategyFactory::createStrategy(strategyType);
    if (strategy) {
        product->setStrategy(std::move(strategy));
    }
}
















































































































































