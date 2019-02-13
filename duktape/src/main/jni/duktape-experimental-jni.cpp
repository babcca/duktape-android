/*
 * Copyright (C) 2016 Square, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <memory>
#include <mutex>
#include <chrono>
#include <jni.h>
#include "DuktapeContext.h"
#include "java/GlobalRef.h"
#include "java/JavaExceptions.h"

extern "C" {
JNIEXPORT void JNICALL
Java_com_squareup_duktape_Duktape_setModuleSearchFunction(
    JNIEnv *env, jclass type, jlong context, jobject object
) {
  DuktapeContext *duktape = reinterpret_cast<DuktapeContext *>(context);
  if (duktape == nullptr) {
    queueNullPointerException(env, "Null Duktape context - did you close your Duktape?");
    return;
  }

  try {
    duktape->setModuleSearchFunction(env, object);
  } catch (const std::invalid_argument &e) {
    queueIllegalArgumentException(env, e.what());
  } catch (const std::exception &e) {
    queueDuktapeException(env, e.what());
  }
}
} // extern "C"
