<script>
    export default{
        inject: ['reload'],
        data(){
            return{

                radio1: this.$store.state.sex,
                checkbox1: this.$store.state.hobbit.eat,
                checkbox2: this.$store.state.hobbit.sleep,

                username_: this.$store.state.username,
                age_: this.$store.state.age,

                email_: this.$store.state.email,
                phonenumber_: this.$store.state.phonenumber,
                design_: this.$store.state.design,

            }
        },
        methods: {
            submitinfo(){
                //this.$axios.get('/user_space/user_changeinfo?k=700').then(res => {console.log('k is:',res);})
                this.$store.state.username = this.username_ ;
                this.$store.state.age = this.age_ ;
                this.$store.state.email = this.email_ ;
                this.$store.state.phonenumber = this.phonenumber_ ;
                this.$store.state.design = this.design_ ;
                this.$store.state.hobbit.eat = this.checkbox1;
                this.$store.state.hobbit.sleep = this.checkbox2;
                this.$store.state.sex = this.radio1;
                alert('保存成功!');
                this.$router.push('/user_space/user_spaceinfo')
                this.reload();
            },
        }
    }
</script>

<template>
    <div>
        <el-card style="height: 700px;width: 800px;margin: auto;top: 0; left: 0; bottom: 0; right: 0;">
            <el-descriptions class="margin-top" title="个人信息" :column="2" >
                <template slot='extra'>
                    <el-button type='primary' size='small' @click="submitinfo">保存</el-button>
                </template>
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-user"></i>用户名
                    </template>
                    <el-input type="text" v-model="username_"></el-input>
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
                    <el-input type="text" v-model="age_"></el-input>
                </el-descriptions-item>
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-male"></i>
                        <i class="el-icon-female"></i>性别
                    </template>
                    <el-radio v-model="radio1" label="male" border>男</el-radio>
                    <el-radio v-model="radio1" label="female" border>女</el-radio>
                </el-descriptions-item>
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-message"></i>邮箱 E-mail
                    </template>
                    <el-input type="text" v-model="email_"></el-input>
                </el-descriptions-item>
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-mobile-phone"></i>手机号码
                    </template>
                    <el-input type="text" v-model="phonenumber_"></el-input>
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
                    <el-checkbox v-model="checkbox1" border>吃饭</el-checkbox>
                    <el-checkbox v-model="checkbox2" border>睡觉</el-checkbox>
                </el-descriptions-item>
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-magic-stick"></i>个性签名
                    </template>
                    <el-input type="text" v-model="design_"></el-input>
                </el-descriptions-item>
                <!-- <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-date"></i>注册日期
                    </template>
                    {{ createdate}}
                </el-descriptions-item> -->
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