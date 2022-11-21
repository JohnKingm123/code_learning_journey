import Vue from 'vue'
import Router from 'vue-router'
import home from '@/views/home/home.vue'

Vue.use(Router)

export default new Router({
    mode: 'history',
    routes: [
        {
            path: '/',
            redirect: '/home'
        },
		{
			path: '/home',
            name: 'home',
			component: home,
		},
		{
            path: '/login_user',
            name: 'login_user',
            component:() => import("@/views/login/login_user.vue")
        },
        {
            path: '/login_select',
            name: 'login_select',
            component:() => import("@/views/login/login_select.vue")
        },
        
        {
            path: '/user_space',
            name: 'user_space',
            component:() => import("@/views/space/user_space.vue"),
            children: [
                {
                    path: "user_spaceinfo",
                    name: "user_spaceinfo",
                    component:() => import("@/components/user_spaceinfo.vue"),
                },
                {
                    path: "user_changepic",
                    name: "user_changepic",
                    component:() => import("@/components/user_changepic.vue"),
                },
                {
                    path: "user_changeinfo",
                    name: "user_changeinfo",
                    component:() => import("@/components/user_changeinfo.vue"),
                },
                {
                    path: "user_changepic_select",
                    name: "user_changepic_select",
                    component:() => import("@/components/user_changepic_select.vue"),
                },
                /*以下是金敏新增router变量*/
                
                {
                    path: "user_relationinfo",
                    name: "user_relationinfo",
                    component:() => import("@/components/JM_user_relationinfo.vue"),
                },
               /* {
                    path: "JM_medSelect1",
                    name: "JM_medSelect1",
                    component:() => import("@/components/JM_medSelect.vue"),
                },
                {
                    path: "JM_medSelect2",
                    name: "JM_medSelect2",
                    component:() => import("@/components/JM_medSelectedList.vue"),
                },*/
            ]
        },
    ]
})
