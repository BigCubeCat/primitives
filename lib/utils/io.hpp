#ifndef IO_HPP
#define IO_HPP

#include "engine/TScene.hpp"

namespace io_utils {

void saveScene(const std::shared_ptr<TScene>& scene, const QString& filename);

std::shared_ptr<TScene> loadScene(const QString& filename);

};  // namespace io_utils

#endif
