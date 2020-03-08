//
//  sphere.hpp
//  Koi
//
//  Created by Jonathan Graham on 1/28/20.
//  Copyright © 2020 Jonathan Graham. All rights reserved.
//

#ifndef KOI_SPHERE_HPP
#define KOI_SPHERE_HPP

#include "shape.hpp"

#include <koi/math/defs.hpp>

namespace koi
{

class Ray;

class Sphere : public Shape
{
public:
    
    /// Default constructor
    Sphere();
    
    /// Constructor
    ///
    /// @param i_radius Input radius to set
    Sphere( float i_radius );

    /// Default destructor
    ~Sphere() override = default;
    
    /// Returns the surface area in local measurement
    ///
    /// @return Computed surface area in local measurement
    float surfaceArea() const override final;
    
    bool intersect( const Ray &i_ray, Intersection &o_intersection ) const override;

private:
    
    /// Radius of the sphere
    float m_radius;
    
    float m_thetaMin;
    float m_thetaMax;
    float m_phiMin;
    float m_phiMax;
    
    float m_deltaTheta;
    float m_deltaPhi;
    
private:
    
    bool intersectPartial( const Ray &i_ray, float i_t, Vec3 &o_hitPosition, float &o_theta, float &o_phi ) const;
};

} // namespace koi

#endif /* KOI_SPHERE_HPP */
