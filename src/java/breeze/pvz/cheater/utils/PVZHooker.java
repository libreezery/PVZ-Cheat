package breeze.pvz.cheater.utils;

public class PVZHooker {

    static {
        System.load("C:\\1Data\\1Projects\\Java\\PVZ Cheat Tool\\lib\\libPVZHooker.dll");
    }

    /**
     * 判断是否成功 HOOK 植物大战僵尸程序
     * @return 是否成功HOOK
     */
    public static native boolean isRunning();

    /**
     * 无限阳光，锁定阳光在 9990
     */
    public static native void infinitSunshine(int num);

    /**
     * 无限金币，锁定金币在 999999999
     */
    public static native void infinitCoin(int num);


    public static native void alterFertilizer(int num);

    public static native void alterTreeFertilizer(int num);

    public static native void alterTreeHeight(int num);

    public static native void alterherbicide(int num);

    public static native void clearCD();

    public static native void alterChocolate(int num);


}
