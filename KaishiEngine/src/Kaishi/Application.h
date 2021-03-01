//
// Created by Matt Whitaker on 28/02/2021.
//

#ifndef KAISHIENGINE_APPLICATION_H
#define KAISHIENGINE_APPLICATION_H

#include "kaipch.h"

namespace Kaishi {

class KaishiApplication {
private:
    char* m_name;
    float m_version;
public:
    KaishiApplication(char* name, float version);

    char *getName() const {
        return m_name;
    }

    void setName(char *name) {
        m_name = name;
    }

    float getVersion() const {
        return m_version;
    }

    void setVersion(float version) {
        m_version = version;
    }
};

} //namespace Kaishi

#endif //KAISHIENGINE_APPLICATION_H
