## Installation
1. Jump to project directory and create a virtual env

```shell
python3 -m venv venv
```

2. Activate virtual env by

```shell
source venv/bin/activate
```

3. Download all required libraries to run python scripts by

```shell
pip install -r requirements.txt
```

4. Find port name in your system and modify the same in **start.py** (line 5).

5. Upload sketch to Arduino and run start.py by

```python3 start.py```