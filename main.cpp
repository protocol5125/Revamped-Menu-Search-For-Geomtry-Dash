#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

class $modify(MyLevelSearchLayer, LevelSearchLayer) {
    bool init(int type) {
        if (!LevelSearchLayer::init(type)) return false;

        auto move = [&](const char* id, CCPoint pos) {
            if (auto n = this->getChildByID(id)) {
                n->setPosition(pos);
            }
            };

        // --- Difficulty filter area ---
        if (auto parent = this->getChildByID("difficulty-filter-menu")) {
            if (auto n = parent->getChildByID("na-filter-button"))      n->setPosition({ -260,  69 }); // haha 69 funny #fuck67
            if (auto n = parent->getChildByID("easy-filter-button"))    n->setPosition({ -224,  69 });
            if (auto n = parent->getChildByID("normal-filter-button"))  n->setPosition({ -260,  29 });
            if (auto n = parent->getChildByID("hard-filter-button"))    n->setPosition({ -224,  29 });
            if (auto n = parent->getChildByID("harder-filter-button"))  n->setPosition({ -260,  -9 });
            if (auto n = parent->getChildByID("insane-filter-button"))  n->setPosition({ -224,  -9 });
            if (auto n = parent->getChildByID("demon-filter-button"))   n->setPosition({ -260, -49 });
            if (auto n = parent->getChildByID("auto-filter-button"))    n->setPosition({ -224, -49 });
            if (auto n = parent->getChildByID("demon-type-filter-button"))
                n->setPosition({ -242, -90 });
        }

        // Background + title tweaks
        if (auto bg = this->getChildByID("difficulty-filters-bg")) {
            bg->setPosition({ 40, 150 });
            bg->setRotation(90.f);
            bg->setScale(2.f);
        }

        move("filters-title", { 45, 260 });
        move("exit-menu", { 37, 297 });

        // --- Length ---
        move("length-filter-menu", { 320, 189 });
        move("length-filters-bg", { 320, 61 });

        auto label = CCLabelBMFont::create("Level Length", "bigFont.fnt");
        label->setPosition({ 320, 100 });
        label->setScale(0.5f);
        this->addChild(label);

        // --- Quick search ---
        move("quick-search-bg", { 320, 175 });
        move("quick-search-menu", { 320, 147 });
        move("quick-search-title", { 320, 252 });

        // --- Search bar ---
        move("level-search-bg", { 320, 290 });
        move("level-search-bar-bg", { 250, 290 });
        move("search-button-menu", { 320, 160 });
        move("search-bar", { 152, 290 });

        auto menu = CCMenu::create();
        menu->setPosition({ 0, 0 });
        menu->setZOrder(1);
        this->addChild(menu);

        auto sprite = CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
        auto button = CCMenuItemSpriteExtra::create(
            sprite,
            nullptr,
            this,
            menu_selector(MyLevelSearchLayer::onButtonPressed)
        );

        button->setPosition({ 35, 30 });
        menu->addChild(button);

        return true;
    }

    void onButtonPressed(CCObject*) {
        FLAlertLayer::create(
            "Credits",
            "Revamped search page,\nmade by <cg>Protocol5125</c>",
            "OK"
        )->show();
    }
};
