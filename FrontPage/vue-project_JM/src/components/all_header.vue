<script>
    let id = 0
    let id2 = 0
    export default{
        data(){
            return{
                header_text: '医•屋健康管理系统',
                header_mod_list: [
                    { id: id++ , text: '首页' },
                    { id: id++ , text: '主要功能' , second_list: [
                        { id2 : id2++ , con: '医疗服务选择' },
                        { id2 : id2++ , con: '订单明细' },              //此处金敏修改了下拉选项，医疗服务选择金敏为每一个选项单独制作一个组件

                    ]},
                    { id: id++ , text: '个人中心' },
                ],
                k : false ,
            }
        },
        methods: {
            list_show(e){
                this.k = ( (e.id == 1) ? true : false )
            },
            Go(e){
                e.id == 0 ? this.$router.push('/') : ( (e.id == 1) ? this.$router.push('/') : this.$router.push('/user_space') )
            },
            
            // GoMedSelection(i){
            //     i.id == 0 ? this.$router.push('/JM_medSelect/JM_medSelect1') :this.$router.push('/JM_medSelect/JM_medSelect1') 
            // }
        },
    }
</script>

<template>
    <div class="mod_header">
        <div class="section_inner">
            <div class="header_logo">
                <p style="font-size: 30px;color: #ffc90e;font: SimHei;">{{ header_text }}</p>
            </div>
            <div class="header_2">
                <ul class="header_filter">
                    <li class="header_filter_item1" v-for="e in header_mod_list" :key="e.id" style="opacity: 0.85;">
                        <router-link to="" @mouseenter.native="list_show(e)" @click.native="Go(e)" >{{ e.text }}</router-link>
                        <ul class="item1_mod1" v-show="k">
                            <li v-for="i in e.second_list" :key="i.id2">
                                
                                <!-- <router-link to=""  @click.native="GoMedSelection(i)" >{{i.con }}</router-link> -->
                                <a :href="'./JM_medSelect'+(i.id2+1)">{{ i.con }}</a>
                            </li>
                        </ul>
                    </li>
                </ul>
            </div>
            <div class="header_login">
                <div class="btn_login">
                    <router-link to="/login_select"><span style="font-weight: bold;">登录/注册</span></router-link>
                </div>
            </div>
        </div>
    </div>
</template>

<style scoped>
    .mod_header{
        position: fixed;
        top: 0; left: 0; right: 0;
        z-index: 1000;
        background-color: #fff;
    }
    .section_inner{
        display: flex;
        text-align: center;
        align-items: center;
        justify-content: space-between;
        height: 100px ;
        margin: 0 auto;
        position: relative;
        padding: 0 0.8rem;
    }
    .header_logo{
        float: left;
        width: 350px;
        height: 100px;
        text-align: center;
        line-height: 100px;
    }
    .header_2{
        float: left;
        width: 1050px;
        height: 100px;
    }
    .header_filter{
        height : 100px;
        line-height: 100px;
        padding-left: 275px;
    }
    .header_filter_item1 {
        list-style: none ;
        float: left;
        font-size: 20px;
        color: #c1c1c1;
    }
    .item1_mod1{
        display: none;
        position: absolute;
        background-color: white;
    }
    .header_filter_item1:hover .item1_mod1{
        display: block;
    }
    .header_login{
        float: left;
        width: 200px;
        height: 100px;
        text-align: center;
        position: relative;
    }
    .btn_login{
        width: 100px;
        height: 50px;
        position: absolute;
        background-color: #c0c0c0;
        position: absolute;
        left: 50%;
        top: 50%;
        text-align: center;
        line-height: 50px;
        transform: translate(-50%,-50%);
        -webkit-border-radius: 10px;
        border-radius: 10px;
    }
</style>
