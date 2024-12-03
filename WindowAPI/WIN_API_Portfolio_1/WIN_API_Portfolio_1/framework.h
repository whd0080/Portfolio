﻿// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <memory>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

#include "Types.h"

// Math
#include "Math/Vector.h"

// Contents
#include "Contents/Objects/Line.h"
#include "Contents/Objects/Collider.h"
#include "Contents/Objects/CircleCollider.h"
#include "Contents/Objects/RectCollider.h"

// Scene
#include "Scenes/Scene.h"

// Program
#include "Program/Program.h"

extern Vector mousePos;