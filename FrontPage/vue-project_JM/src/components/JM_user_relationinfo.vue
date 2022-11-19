<script>

let id = 0

export default {
  data() {
    return {
      newRelation: '',
      Relations: []
    }
  },
  methods: {
    addRelation() {
      this.Relations.push({ id: id++, text: this.newRelation })
      this.newRelation = ''
    },
    removeRelation(Relation) {
      this.Relations = this.Relations.filter((t) => t !== Relation)
    }
  }
}
</script>

<template>
<div>
    <div class="total">
        <el-card style="height: 700px;width: 800px;margin: auto;top: 0; left: 0; bottom: 0; right: 0;">
            <el-descriptions class="margin-top" title="关联信息" :column="1" >
                <el-descriptions-item>
                    <form @submit.prevent="addRelation">
                        <input v-model="newRelation">姓名<br>
                        <input >用户名<br>
                        <input >密码<br>
                        <button>新增</button>    <!--需要后端数据作验证-->
                    </form>
                    
                    
                </el-descriptions-item>
             
   <!--                <br>
                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-relation"></i>用户名
                    </template>
                    <el-input type="text" v-model="itsUserName"></el-input>
                </el-descriptions-item>
                <br>

                <el-descriptions-item>
                    <template slot="label">
                        <i class="el-icon-relation"></i>密码
                    </template>
                    <el-input type="text" v-model="itsPassWD"></el-input>
                </el-descriptions-item>
                <br>
-->
            </el-descriptions>
            
            <el-descriptions>
                <el-descriptions-item>
                    <label>关联列表</label>
                </el-descriptions-item>
            </el-descriptions>
            
            <el-descriptions>
                <el-descriptions-item>     
                    <ul>
                         <li v-for="Relation in Relations" :key="Relation.id">
                             {{ Relation.text }}
                         <button @click="removeRelation(Relation)">X</button>
                         </li>
                     </ul>
                 </el-descriptions-item>

            </el-descriptions>

        </el-card>
    </div>
</div>

</template>

<style scoped>
    .el-descriptions{
        font-size: 18px;
    }
</style>