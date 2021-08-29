//
// Created by ppitu on 29.08.2021.
//

#include "Pattern.h"

void Pattern::setName(const QString &name) {
    mName = name;
}

QString Pattern::getName() const {
    return mName;
}

void Pattern::setId(int id) {
    mId = id;
}

int Pattern::getId() const {
    return mId;
}

Pattern::Pattern() = default;
