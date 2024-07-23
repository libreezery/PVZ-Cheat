//
// Created by BREEZE on 2024/7/19.
//

#include "breeze_pvz_cheater_utils_PVZHooker.h"

#include "PVZTools.h"


JNIEXPORT jboolean JNICALL Java_breeze_pvz_cheater_utils_PVZHooker_isRunning
        (JNIEnv *env, jclass clazz) {
    return startHook();
}

/*
 * Class:     breeze_pvz_cheater_utils_PVZHooker
 * Method:    infinitSunshine
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_breeze_pvz_cheater_utils_PVZHooker_infinitSunshine
        (JNIEnv *env, jclass clazz, jint val) {
    if (canBeHooked) {
        setSunshine(val);
    }
}

/*
 * Class:     breeze_pvz_cheater_utils_PVZHooker
 * Method:    infinitCoin
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_breeze_pvz_cheater_utils_PVZHooker_infinitCoin
        (JNIEnv *env, jclass clazz, jint val) {
    if (canBeHooked) {
        setCoin(val);
    }
}

/*
 * Class:     breeze_pvz_cheater_utils_PVZHooker
 * Method:    alterFertilizer
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_breeze_pvz_cheater_utils_PVZHooker_alterFertilizer
        (JNIEnv *env, jclass clazz, jint val) {
    if (canBeHooked) {
        setFertilizer(val);
    }
}

/*
 * Class:     breeze_pvz_cheater_utils_PVZHooker
 * Method:    alterherbicide
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_breeze_pvz_cheater_utils_PVZHooker_alterherbicide
        (JNIEnv *env, jclass clazz, jint val) {
    if (canBeHooked) {
        setHerbicide(val);
    }
}

/*
 * Class:     breeze_pvz_cheater_utils_PVZHooker
 * Method:    alterTreeHeight
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_breeze_pvz_cheater_utils_PVZHooker_alterTreeHeight
        (JNIEnv *env, jclass clazz, jint val) {
    if (canBeHooked) {
        if (val > 0) {
            setTreeHeight((int) getTreeHeight() + 100);
        } else if (val < 0 && getTreeHeight() > 100) {
            setTreeHeight((int) getTreeHeight() - 100);
        } else {
            setTreeHeight(0);
        }
    }
}


/*
 * Class:     breeze_pvz_cheater_utils_PVZHooker
 * Method:    alterTreeFertilizer
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_breeze_pvz_cheater_utils_PVZHooker_alterTreeFertilizer
        (JNIEnv *env, jclass clazz, jint val) {
    if (canBeHooked) {
        setTreeFertilizer(val);
    }
}