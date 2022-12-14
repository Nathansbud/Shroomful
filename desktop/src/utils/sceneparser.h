#pragma once

#include "scenedata.h"
#include <vector>
#include <string>
#include <map>
#include "rgba.h"

// Struct which contains data for a single primitive, to be used for rendering
struct RenderShapeData {
    ScenePrimitive primitive;

    glm::mat4 ctm; // the cumulative transformation matrix (ctm)
    glm::mat4 ictm; // the inverse ctm
    glm::mat3 nictm; // transpose, inverse top left ctm

    glm::mat4 ctmInitial; // initial CTM to be used for objects that might translate/rotate
};

struct TextureData {
    std::vector<RGBA> textureMap;
    int width;
    int height;
};


// Struct which contains all the data needed to render a scene
struct RenderData {
    SceneGlobalData globalData;
    SceneCameraData cameraData;

    std::vector<SceneLightData> lights;
    std::vector<RenderShapeData> shapes;
    std::map<std::string, TextureData> textures;
};



class SceneParser {
public:
    // Parse the scene and store the results in renderData.
    // @param filepath    The path of the scene file to load.
    // @param renderData  On return, this will contain the metadata of the loaded scene.
    // @return            A boolean value indicating whether the parse was successful.
    static bool parse(std::string filepath, RenderData &renderData);
    static bool loadTexturesFromPaths(std::map<std::string, TextureData>& textures, std::vector<std::string>& shapes);
};

