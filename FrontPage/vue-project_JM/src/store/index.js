import Vue from 'vue'
import Vuex from 'vuex'

import pic_default from '@/assets/image/pic_default.jpeg'

Vue.use(Vuex)

const store = new Vuex.Store({
    state:{
        user_pic: pic_default,
        
        username: '10001',
        age: '20',
        sex: 'female',
        email: 'shnu.com',
        phonenumber: '10086',
        hobbit: {
            eat: true,
            sleep: true,
        },
        design: 'hello everybody',

    },
})

export default store
