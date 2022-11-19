<script>
    export default {
        // beforeRouteEnter: (to, from, next) => {
        //     console.log("准备进入个人信息页");
        //     let islogin = sessionStorage.getItem("isLogin")
        //     if(!islogin){
        //     next({path:'/login'});
        //     }//确认是不是已经登录，否则返回登录界面（后面传数据再改）
        //     next();
        // },
        data() {
            return {
                user:{
                    userpic : this.$store.state.user_pic,
                    username: '游客'
                }
            }
        },
        methods:{
            Gospaceinfo(){
                this.$router.push('/user_space/user_spaceinfo') 
            },
            Gochangepic(){
                this.$router.push('/user_space/user_changepic') 
            },
            Gochangeinfo(){
                this.$router.push('/user_space/user_changeinfo') 
            },
            Gorelationinfo(){
                this.$router.push('/user_space/user_relationinfo') //金敏 跳转至家人关联信息

            }

        }
    }
</script>

<template>
    <div class="total">
        <div style="height: 800px;width: 1200px;margin: auto;top: 0; left: 0; bottom: 0; right: 0;position: absolute;">
            <el-container style="height: 800px; border: 1px solid #eee;">
                <el-aside width="200px" style="margin-top: 1%" >
                    <div style="width: 190px;background-color: white;padding: 5px;margin: auto">
                        <img :src="user.userpic" width="150px" height="150px" style="border-radius: 300px;margin-left: 8%">
                        <br>
                        <br>
                        <p style="margin:0 auto;text-align: center">{{user.username}}</p>
                    </div>
                    <br>
                    <br>
                    <el-menu :default-openeds="['1','2']">
                        <el-submenu index="1">
                        <template slot="title"><i class="el-icon-message"></i>用户中心</template>
                        <el-menu-item-group>
                            <el-menu-item index="1-1" @click.native="Gospaceinfo">个人信息</el-menu-item>
                            <el-menu-item index="1-2" @click.native="Gochangepic">修改头像</el-menu-item>
                            <el-menu-item index="1-3" @click.native="Gochangeinfo">修改信息</el-menu-item>
                            <el-menu-item index="1-4" @click.native="Gorelationinfo">家人关联</el-menu-item>   <!--金敏 新增一个家人关联的按钮，稍后补全方法-->
                        </el-menu-item-group>
                        </el-submenu>
                        <!-- <el-submenu index="2">
                        <template slot="title"><i class="el-icon-menu"></i>博客管理</template>
                        <el-menu-item-group>
                            <router-link to="/space/bokelist"><el-menu-item index="2-1">博客列表</el-menu-item></router-link>
                            <router-link to="/space/wirterboke"><el-menu-item index="2-2">书写文章</el-menu-item></router-link>
                        </el-menu-item-group>
                        </el-submenu> -->
                    </el-menu>
                </el-aside>
                <el-container style="background-color: white">
                    <el-main>
                        <router-view></router-view>
                    </el-main>
                </el-container>
            </el-container>
        </div>
    </div>
</template>

<style scoped>
    .total{
        max-width: 100%;
        height: 800px;
        margin: 0 auto;
        position: relative;
        /* //background-color: #ddd; */
    }
    .el-header {
        background-color: #B3C0D1;
        color: #333;
        line-height: 60px;
    }

    .el-aside {
        color: #333;
    }
    .router-link {
        text-decoration: none;
        color: #fff;
    }
</style>