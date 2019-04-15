#ifndef ZERKOLA_INCLUDE_GEOMETRY_H_
#define ZERKOLA_INCLUDE_GEOMETRY_H_

#include <math.h>
#include <vector>
#include <assert.h>
#include <matplotlibcpp.h>
#include <iostream>
#include <Eigen/Dense>
#include <string>

namespace geometry {

	//constants
	const double kRAD_TO_DEG = 57.2958;
	//constants

	class PlotObj {
		//A general object to be plotted
		//Object will have CG point and pose (Pose2D) as well as plotted shape (plot_shape) and collision circle radius (rad_col)
		protected:
		//members
		Eigen::Vector2d CG_; //Center of object. Object will rotate w.r.t. this point.
		Eigen::Vector2d dir_; //Direction vector which object is pointing (defines forward). Always normalized.
		std::vector<Eigen::Vector2d> polygon_; //Polygon which define plotted shape. Must start and end at the same point
		double rad_collision_; //Radius of collision with center of circle at CG_
		std::string color_; //color of object
		//methods
		void calc_rad_collision(); //Calculates radius of collision for given polygon_

		public:
		//constructors
		PlotObj();
		PlotObj(const double& x_start, const double& y_start,const std::string& color="k");
		~PlotObj();

		//methods
		void Plot() const; //Plots the current object boundary
		bool CheckBoundaryCollision(const double& NorthLimit_, const double& EastLimit_, const double& SouthLimit_, const double& WestLimit_) const; //Checks if PlotObj collided with boundary
	};

} // namespace geometry

#endif // ZERKOLA_INCLUDE_GEOMETRY_H_
