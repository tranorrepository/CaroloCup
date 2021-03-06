/*
 * Copyright (c) Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#include "core/data/Constants.h"
#include "core/data/environment/Point3.h"
#include "hesperia/decorator/twoD/Renderer2D.h"

namespace hesperia {
    namespace decorator {
        namespace twoD {

            using namespace std;
            using namespace core::data;
            using namespace core::data::environment;
            using namespace hesperia::decorator::models;

            Renderer2D::Renderer2D() {}

            Renderer2D::~Renderer2D() {}

            void Renderer2D::beginPainting() {
                // Not implemented.
            }

            void Renderer2D::endPainting() {
                // Not implemented.
            }

            void Renderer2D::drawPolyLine(const vector<Point3> &listOfPoints) {
                if (listOfPoints.size() > 1) {
                    for(uint32_t i = 0; i < listOfPoints.size() - 1; i++) {
                        drawLine(listOfPoints[i], listOfPoints[i+1]);
                    }
                }
            }

            void Renderer2D::drawPolyLine(const vector<Point3> &listOfPoints, const double &/*height*/) {
                // Ignore height.
                drawPolyLine(listOfPoints);
            }


            void Renderer2D::drawTriangleSet(const TriangleSet &ts) {
                drawTriangleSet(ts, Point3(), Point3());
            }

            void Renderer2D::drawListOfTriangleSets(const vector<TriangleSet> &listOfTriangleSets) {
                drawListOfTriangleSets(listOfTriangleSets, Point3(), Point3());
            }

            void Renderer2D::drawTriangleSet(const TriangleSet &ts, const Point3 &position, const Point3 &rotation) {
                vector<Point3> points;
                vector<Point3>::const_iterator it = ts.m_vertices.begin();
                while (it != ts.m_vertices.end()) {
                    Point3 p = (*it);
                    p.rotateX(rotation.getX());
                    p.rotateY(rotation.getY());
                    p.rotateZ(rotation.getZ());

                    p += position;

                    points.push_back(p);

                    it++;
                }

                drawPolyLine(points);
            }

            void Renderer2D::drawListOfTriangleSets(const vector<hesperia::decorator::models::TriangleSet> &listOfTriangleSets, const core::data::environment::Point3 &position, const core::data::environment::Point3 &rotation) {
                vector<TriangleSet>::const_iterator it = listOfTriangleSets.begin();
                while (it != listOfTriangleSets.end()) {
                    if ((*it).m_vertices.size() > 0) {
                        setColor((*it).m_material.getDiffuse());
                        setLineWidth(1.0);

                        // Fix inside OBJ-Wavefront-Models (OBJXArchive) (rotated 90°)!
                        vector<Point3> vertices = (*it).m_vertices;
                        vector<Point3> rotatedVertices;
                        vector<Point3>::iterator jt = vertices.begin();
                        while (jt != vertices.end()) {
                            Point3 p = (*jt).rotateX(Constants::PI/2.0);

                            p.rotateX(rotation.getX());
                            p.rotateY(rotation.getY());
                            p.rotateZ(rotation.getZ());
                            p += position;

                            rotatedVertices.push_back(p);
                            jt++;
                        }

                        drawPolyLine(rotatedVertices);
                    }
                    it++;
                }
            }

        }
    }
} // hesperia::decorator::twoD
