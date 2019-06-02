#include <r2d2.h>
#include <geometry.h>
#include <iostream>

namespace r2d2 {

R2D2::R2D2() {};

R2D2::~R2D2() {};

R2D2::R2D2(graphics::Graphics* graphics_ptr, gc::PlayerColor player_color, std::list<missile::Missile*>* missiles_ptr):
    tank::Tank(graphics_ptr, player_color, missiles_ptr),

    _enemyTarget(nullptr)
    {};

void R2D2::_turn() {
    //If (tank in danger)
        //Evasive action
    //Else
        //Aggressive action
    //Check if tank is in danger
    if (_dangerCheck()) {
        std::cout << "Evasive Maneuver!" << std::endl;
        //Evasive maneuver
        _evasiveManeuver();
    }
    return;
};

void R2D2::_evasiveManeuver() {
    _translate_body_cmnd = gc::LinearDirections::FORWARD;
    return;
}

bool R2D2::_dangerCheck() const {
    return(_directMissileHitCheck());
}

bool R2D2::_directMissileHitCheck() const {
    for (auto missile : (*_missiles_ptr)) {
        Eigen::Vector2d I;
        double lambda;
        if (geo::LineCircleIntersection(missile->center(), missile->dir(), geo::Cast3D2Dd(center()), gc::TANK_RAD_COL, lambda, I)) {
            return(true);
        }
    }
    return(false);
}

}