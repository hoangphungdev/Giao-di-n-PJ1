const express = require('express');
const { spawn } = require('child_process');
const fs = require('fs');
const path = require('path');
const app = express();
const cors = require('cors');
app.use(cors());

app.use(express.json()); // for parsing application/json

// Phục vụ tệp HTML từ thư mục 'public'
app.use(express.static(path.join(__dirname, 'Giao diện')));

app.post('/run-cpp-code', (req, res) => {
    // Mã C++ từ dữ liệu nhập vào
    const cppCode = req.body.cppCode;
    const inputParams = req.body.inputParams;

    // Ghi mã C++ vào một tệp tạm thời
    fs.writeFile('temp.cpp', cppCode, (err) => {
        console.log('Mã C++ đã được ghi vào tệp tạm thời!');
        if (err) throw err;

        // Biên dịch mã C++
        const compile = spawn('g++', ['temp.cpp', '-o', 'temp']);
        compile.on('close', (code) => {
            if (code !== 0) {
                console.log(`compile process exited with code ${code}`);
            } else {
                // Chạy chương trình đã biên dịch
                const run = spawn('./temp');
                run.stdin.write(inputParams + "\n");
                run.stdin.end();

                run.stdout.on('data', (data) => {
                    console.log(`stdout: ${data}`);
                    // Gửi kết quả đến trình duyệt
                    res.send(data.toString());
                });

                run.stderr.on('data', (data) => {
                    console.error(`stderr: ${data}`);
                });

                run.on('close', (code) => {
                    console.log(`run process exited with code ${code}`);
                });
            }
        });
    });
});

app.listen(3000, () => {
    console.log('Server is running on port 3000');
});
