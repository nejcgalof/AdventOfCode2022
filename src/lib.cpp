#include "lib.hpp"
#include <internal_use_only/config.hpp>
#include <sstream>
#include <string_view>

namespace lib {
  std::string LibInformations()
  {
    std::stringstream info;
    info << "Lib: " << cmake::library_name << "\n"
         << "Version: " << cmake::library_version << "." << cmake::git_hash << "\n";
    return info.str();
  }
} // namespace lib
