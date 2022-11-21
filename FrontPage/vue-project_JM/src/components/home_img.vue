<script>
    import img1 from '@/assets/image/backimage1.jpg'
    import img2 from '@/assets/image/backimage2.png'
    import img3 from '@/assets/image/backimage3.jpg'
    export default{
        data(){
            return {
                btn: false ,
                mark : 0 ,
                imglist: [
                    { con: img1 },
                    { con: img2 },
                    { con: img3 },
                ],
                timer: 4000, //设置循环时间
                width: 100, //移动的长度
            }
        },
        methods: {  
            stop() {
                clearInterval(this.timer);
            },
            start() {
                this.timer = setInterval(() => {
                    this.go(-1), console.log("开始计时");
                }, this.timer);
            },

            go(direc) {
                console.log(direc);
                if (direc == -1) {
                    this.mark = this.mark >= this.imglist.length - 1 ? 0 : this.mark + 1;
                } else if (direc == 1) {
                    this.mark = this.mark <= 0 ? this.imglist.length - 1 : this.mark - 1;
                }
                console.log("mark:", this.mark);
                this.move(); //移动
            },
            move() {
                this.width = -400 * this.mark;
                console.log("width:", this.width);
            },
            btnshow(){
                this.btn = true
            },
            btnhide(){
                this.btn = false
            },
        }, 
        computed: {
            changepic(){
                return {
                    transform: `translate3d(${this.width}px, 0, 0)`, //主要实现核心
                };
            },
        },
        mounted(){
            console.log('挂载完成');
            this.start();
        },
        beforeDestroy() {
            this.stop();
        },
    }
</script>

<template>
    <div class="mod_image" @mouseenter="btnshow" @mouseleave="btnhide">
        <div class="section_inner_image" v-for="(imgurl, id) in imglist" v-show="id===mark" :key="id">
            <img :src="imgurl.con" style="object-fit: cover;width: 100%;height: 600px;">
        </div>
        <div class="bar">
            <span v-for="(item, id) in imglist" :class="{ 'active':id===mark }" :key="id"></span>
        </div>
        <div class="c_box">
            <button class="c_box_btn" style="float: left;" id="c_box_leftbtn" @click="go(1)" v-show="btn">&lt;</button>
            <button class="c_box_btn" style="float: right;" id="c_box_rightbtn" @click="go(-1)" v-show="btn">&gt;</button>
            <h4 style="font-size: 80px;color: black;">科技改变生活</h4>
            <div style="text-align: center;font-size: 16px;color: black;">Technology changes life</div>
        </div>
    </div>
</template>

<style scoped>
    .mod_image{
        max-width: 100%;
        height: 600px;
        margin: 0 auto;
        position: relative;
    }
    .section_inner_image{
        max-width: 100%;
        height: 600px;
        margin: 0 auto;
        position: relative;
    }
    .c_box{
        position: absolute;
        height: 160px;
        max-width: 100%;
        margin: auto;
        top: 0; left: 0; bottom: 0; right: 0;
        text-align: center;
    }
    .c_box_btn{
        height: 100px;
        width: 80px;
        line-height: 100px;
        font-size: 60px;
        color: #808080;
        /*background-color: #808080;*/
        opacity: 0.5;
    }
    .bar {  
        position: absolute;  
        width: 100%;  
        bottom: 10px;  
        margin: 0 auto;  
        z-index: 10;  
        text-align: center;  
    }  
    .bar span {  
        width: 20px;  
        height: 20px;  
        border: 0.5px solid;  
        background: white;  
        display: inline-block;  
        margin-right: 10px;  
        -webkit-border-radius: 20px;
        border-radius: 20px;
        opacity: 0.3;
    }  
    .active {  
        background: #808080 !important; 
    }
</style>