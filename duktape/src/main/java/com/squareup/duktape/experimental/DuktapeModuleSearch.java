package com.squareup.duktape.experimental;

import android.support.annotation.Nullable;

public interface DuktapeModuleSearch {

    boolean loadNativeModule(String id);

    @Nullable String loadScriptModule(String id);
}
