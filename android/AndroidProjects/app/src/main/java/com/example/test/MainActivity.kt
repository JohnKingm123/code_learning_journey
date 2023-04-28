package com.example.test

import android.content.Context
import android.graphics.BitmapFactory
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import com.example.test.databinding.ActivityMainBinding
import java.io.File
import java.io.FileInputStream

lateinit var binding: ActivityMainBinding

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)


        binding.button.setOnClickListener(){
            val inputStream =resources.openRawResource(R.raw.test)
            val len = inputStream.available()
            val buffer = ByteArray(len)
            inputStream.read(buffer)

            val content:String = String(buffer)

            binding.textView.text = content
        }
        binding.button2.setOnClickListener(){
            val filename = "assetsText.txt"
            val inputStream = assets.open(filename)
            val len = inputStream.available()
            val buffer = ByteArray(len)
            inputStream.read(buffer)

            val content:String = String(buffer)

            binding.textView.text = content

        }

        binding.button3.setOnClickListener(){
            val filename = "test2.txt"
            val content:String =binding.usrInput.text.toString()
            val fos = openFileOutput(filename, Context.MODE_PRIVATE)

            val buffer:ByteArray = content.toByteArray()
            fos.write(buffer)

            fos.flush()
            fos.close()

        }
        binding.button4.setOnClickListener(){
            val filename = "test2.txt"
            val fis = openFileInput(filename)
            val buffer = ByteArray(fis.available())
            fis.read(buffer)

            val content = String(buffer)
            binding.textView.text = content

        }
        binding.button5.setOnClickListener(){
//            val pic = File(Environment.getExternalStorageDirectory(),"/storage/emulated/0/foreignFiles/f.jpg")
//            val fis = FileInputStream(pic)
//            val bitmap = BitmapFactory.decodeStream(fis)
//
//            binding.imageView.setImageBitmap(bitmap)
//            fis.close()


        }




    }
}