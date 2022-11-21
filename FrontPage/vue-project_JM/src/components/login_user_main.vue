<script> 

    export default {
        data(){
            return{
                ifhidden1: 'hidden',
                ifhidden2: '',
                loginForm: [
                    { login_username : '' },
                    { login_password : '' },
                ],
                
                userToken: '',
            }
        },
        created(){
        },
        mounted(){
        },
        methods:{
            LoginGo(){
                const Regist = this.$refs.form_box
                console.log( Regist );
                Regist.style.transform = 'translateX(0%)'
                this.ifhidden1 = 'hidden'
                this.ifhidden2 = ''
            },
            registerGo(){
                const Regist = this.$refs.form_box
                console.log( Regist );
                Regist.style.transform = 'translateX(80%)'
                this.ifhidden1 = ''
                this.ifhidden2 = 'hidden'
            },
            
        }
    }
</script>


<template>
    <div class="tot">
        <div class="container">
            <div class="form-box" ref="form_box">
                <div class="register-box" :id="ifhidden1">
                    <h1>注册</h1>
                    <input type="text" placeholder="username">
                    <input type="email" placeholder="email">
                    <input type="password" placeholder="password">
                    <input type="password" placeholder="acknowledge password">
                    <button>注册</button>
                </div>
                <div class="login-box" :id="ifhidden2">
                    <h1>登录</h1>
                    <input type="text" placeholder="username" v-model="loginForm.login_username">
                    <input type="password" placeholder="password" v-model="loginForm.login_password">
                    <button>登录</button>
                </div>
            </div>
            <div class="con-box left">
                <h2><span>您好!</span></h2>
                <img  src="@/assets/image/login-logo.png" alt="" style="-webkit-border-radius: 100px;-moz-border-radius: 100px;">
                <p>我已有账号</p>
                <button id="login" @click="LoginGo">登录</button>
            </div>
            <div class="con-box right">
                <h2><span>您好!</span></h2>
                <img src="@/assets/image/login-logo.png" alt="" style="-webkit-border-radius: 100px;-moz-border-radius: 100px;">
                <p>我未有账户</p>
                <button id="register" @click="registerGo">注册</button>
            </div>
        </div>
    </div>
</template>



<style>
   .tot{
        height: 800px;
        display: flex;
        justify-content: center;
        align-items: center;
        background: linear-gradient(200deg,white,skyblue);
    }
    .container{
        background-color: #fff;
        width: 650px;
        height: 415px;
        border-radius: 5px;
        box-shadow: 5px 5px 5px rgba(0,0,0,0.1);
        position: relative;
    }
    .form-box{
        position: absolute;
        top: -10%;
        left: 5%;
        background-color: rgb(126, 129, 142);
        width: 320px;
        height: 500px;
        border-radius: 5px;
        box-shadow: 2px 0 10px rgba(0,0,0,0.1);
        display: flex;
        justify-content: center;
        align-items: center;
        z-index: 2;
        transition: 0.5s ease-in-out;
    }
    .register-box,.login-box{
        display: flex;
        flex-direction: column;
        align-items: center;
        width: 100%;
    }
    #hidden{
        display: none;
        transition: 0.5s;
    }
    h1{
        text-align: center;
        margin-bottom: 25px;
        text-transform: uppercase;
        color: #fff;
        letter-spacing: 5px;
    }
    input{
        background-color: transparent;
        width: 70%;
        color: #fff;
        /* caret-color: #000000; */
        border: none;
        border-bottom: 1px solid rgba(255,255,255,0.4);
        padding: 10px 0;
        text-indent: 10px;
        margin: 8px 0;
        font-size: 14px;
        letter-spacing: 2px;
    }
    input::placeholder{
        color: #ffffff;
    }
    input:focus{
        color: #ffffff;
        outline: none;
        border-bottom: 1px solid rgb(0, 0, 0);
        transition: 0.5s;
    }
    input:focus::placeholder{
        opacity: 0;
    }
    .form-box button{
        width: 70%;
        margin-top: 35px;
        background-color: rgb(66, 62, 62);
        outline: none;
        border-radius: 8px;
        padding: 13px;
        color: #ffffff;
        letter-spacing: 2px;
        border: none;
        cursor: pointer;
    }
    .form-box button:hover{
        background-color: #000000;
        color: #ffffff;
        transition: background-color 0.5s ease;
    }
    .con-box{
        width: 50%;
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        position: absolute;
        top: 50%;
        transform: translateY(-50%);
    }
    .con-box.left{
        left: -2%;
    }
    .con-box.right{
        right: -2%;
    }
    .con-box h2{
        color: #8e9aaf;
        font-size: 25px;
        font-weight: bold;
        letter-spacing: 3px;
        text-align: center;
        margin-bottom: 4px;
    }
    .con-box span{
        color: rgb(66, 62, 62);
    }
    .con-box img{
        width: 150px;
        height: 150px;
        opacity: 0.9;
        margin: 40px 0;
    }
    .con-box button{
        margin-top: 3%;
        background-color: #fff;
        color: rgb(66, 62, 62);
        border: 1px solid rgb(66, 62, 62)8;
        padding: 6px 10px;
        border-radius: 5px;
        letter-spacing: 1px;
        outline: none;
        cursor: pointer;
    }
</style>