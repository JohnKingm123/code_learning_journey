<script>

</script>

<template>
    <div>
        <div class="mod_menu">
            <h4 style="font-size:25px;">关 于 我 们</h4>
        </div>
        <div class="mod_tail">
            <p>一支有凝聚力并致力于健康的开发队伍</p>
            <router-link to="/login_select"></router-link>
        </div>
    </div>
    
</template>

<style scoped>
.mod_menu{
    max-width: 100%;
    height: 50px;
    position: relative;
    margin: 0 auto;
    text-align: center;
    line-height: 50px;
    /*background: -webkit-linear-gradient(top,white,skyblue);*/
    background-color: #f1f1f1;
    border-bottom: 1px solid #ddd;
}
.mod_tail{
    max-width: 100%;
    height: 150px;
    text-align: center;
    line-height: 150px;
    background-color: #808080;
    font-weight: bolder;
    font-size: larger;
}
</style>