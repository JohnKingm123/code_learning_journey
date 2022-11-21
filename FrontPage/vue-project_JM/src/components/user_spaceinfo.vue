<script>
    export default{
        data(){
            return {
                eat_ : '吃饭',
                sleep_ : '睡觉', 
                eatandsleep: '吃饭和睡觉',
                other_wise: '无',

                male_ : '男',
                female_ : '女'
            }
        },
    }
</script>

<template>
    <div>
        <el-card style="height: 700px;width: 800px;margin: auto;top: 0; left: 0; bottom: 0; right: 0;">
            <el-descriptions class="margin-top" title="个人信息" :column="2" >
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-user"></i>用户名
                    </template>
                    {{ $store.state.username }}
                </el-descriptions-item>
                <!-- <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-s-custom"></i>昵称
                    </template>
                    {{ nickname }}
                </el-descriptions-item> -->
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-odometer"></i>年龄
                    </template>
                    {{ $store.state.age }}
                </el-descriptions-item>
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-male"></i>
                        <i class="el-icon-female"></i>性别
                    </template>
                    <el-tag size="small">{{ $store.state.sex == 'male' ?  this.male_ : this.female_ }}</el-tag>
                </el-descriptions-item>
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-message"></i>邮箱 E-mail
                    </template>
                    {{ $store.state.email }}
                </el-descriptions-item>
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-mobile-phone"></i>手机号码
                    </template>
                    {{ $store.state.phonenumber }}
                </el-descriptions-item>
                <!-- <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-location-outline"></i>地区
                    </template>
                    {{ area }}
                </el-descriptions-item>
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-office-building"></i>职业
                    </template>
                    {{ work }}
                </el-descriptions-item> -->
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-basketball"></i>兴趣爱好
                    </template>
                    {{ (($store.state.hobbit.eat == true)&&($store.state.hobbit.sleep == true)) ? 
                        (this.eatandsleep) : (
                            ($store.state.hobbit.eat == true) ? 
                                (this.eat_) : ( 
                                    ($store.state.hobbit.sleep == true) ?
                                        (this.sleep_) : (this.other_wise)
                                            )
                            )
                    }}
                </el-descriptions-item>
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-magic-stick"></i>个性签名
                    </template>
                    {{ $store.state.design }}
                </el-descriptions-item>
                <!-- <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-date"></i>注册日期
                    </template>
                    {{ createdate}} -->
                <!-- </el-descriptions-item> -->
            </el-descriptions>
            
            <div style="width: auto;height: 400px;background-color: #ddd;opacity: 0.7;text-align: center;line-height: 400px;">img</div>
        </el-card>
    </div>
</template>

<style scoped>
    .el-descriptions{
        font-size: 18px;
    }
</style>