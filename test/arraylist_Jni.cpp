#include <bits/stdc++.h>
#include <vector>
#include <jni.h>

class Point2f {
public:
    double x;
    double y;
    Point2f(double x, double y) : x(x), y(y) {}
};

extern "C" JNIEXPORT void JNICALL Java_com_example_ImageProcessingActivity_transferPointsToNative(JNIEnv* env, jobject self, jobject input) {
    jclass alCls = env->FindClass("java/util/ArrayList");
    jclass ptCls = env->FindClass("java/awt/Point");

    if (alCls == nullptr || ptCls == nullptr) {
        return;
    }

    jmethodID alGetId  = env->GetMethodID(alCls, "get", "(I)Ljava/lang/Object;");
    jmethodID alSizeId = env->GetMethodID(alCls, "size", "()I");
    jmethodID ptGetXId = env->GetMethodID(ptCls, "getX", "()D");
    jmethodID ptGetYId = env->GetMethodID(ptCls, "getY", "()D");

    if (alGetId == nullptr || alSizeId == nullptr || ptGetXId == nullptr || ptGetYId == nullptr) {
        env->DeleteLocalRef(alCls);
        env->DeleteLocalRef(ptCls);
        return;
    }

    int pointCount = static_cast<int>(env->CallIntMethod(input, alSizeId));

    if (pointCount < 1) {
        env->DeleteLocalRef(alCls);
        env->DeleteLocalRef(ptCls);
        return;
    }

    std::vector<Point2f> points;
    points.reserve(pointCount);
    double x, y;

    for (int i = 0; i < pointCount; ++i) {
        jobject point = env->CallObjectMethod(input, alGetId, i);
        x = static_cast<double>(env->CallDoubleMethod(point, ptGetXId));
        y = static_cast<double>(env->CallDoubleMethod(point, ptGetYId));
        env->DeleteLocalRef(point);

        points.push_back(Point2f(x, y));
    }

    env->DeleteLocalRef(alCls);
    env->DeleteLocalRef(ptCls);
}
