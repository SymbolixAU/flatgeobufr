#include <fstream>
#include <sstream>
#include <iostream>

#include <mapbox/geojson.hpp>

#include "flatbuffers/flatbuffers.h"
//#include "feature_generated.h"
//#include "header_generated.h"

#include "geojson.h"

//#include "packedrtree.h"

#include <Rcpp.h>

using namespace flatbuffers;
using namespace FlatGeobuf;

const std::string getFixture(const std::string &path)
{
  std::ifstream t(path);
  std::stringstream buffer;
  buffer << t.rdbuf();
  return buffer.str();
}

// [[Rcpp::export]]
void test( const char* fp ) {

  auto expected = mapbox::geojson::parse(getFixture(fp)).get< feature_collection >();
  // auto flatgeobuf = serialize(expected);
  // auto actual = deserialize(flatgeobuf);

}
