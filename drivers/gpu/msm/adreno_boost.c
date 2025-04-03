#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include "adreno.h"

static int adreno_boost_enable = 1;
module_param(adreno_boost_enable, int, 0644);
MODULE_PARM_DESC(adreno_boost_enable, "Enable Adreno Boost feature");

void adreno_boost(struct adreno_device *adreno_dev) {
    if (!adreno_boost_enable) return;

    // GPUクロックを最大に設定
    msm_gpu_set_freq(adreno_dev->gpu, adreno_dev->gpu->fast_rate);
}
EXPORT_SYMBOL_GPL(adreno_boost);

static int __init adreno_boost_init(void) {
    pr_info("Adreno Boost initialized\n");
    return 0;
}

static void __exit adreno_boost_exit(void) {
    pr_info("Adreno Boost removed\n");
}

module_init(adreno_boost_init);
module_exit(adreno_boost_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Adreno Boost Driver");
MODULE_AUTHOR("Rakkashin");
