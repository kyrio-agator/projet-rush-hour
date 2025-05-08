#include "type.h"

#include <filesystem>
#include <fstream>
#include "../include/json/json.hpp"
using json = nlohmann::json;
namespace fs =std::filesystem;

str selectJson(str plt_dir);