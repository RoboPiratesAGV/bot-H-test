import serial
import time

# In windows, change PORT to whatever it is
arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.05)


class Bot:
    def __init__(self):
        """
        List of all possible actions:
        0 for Halt
        1 for Forward
        2 for Reverse
        3 for Forward-Turn-Left
        4 for Forward-Turn-Right
        5 for Reverse-Turn-Left
        6 for Reverse-Turn-Right
        """
        self.actions = {0: "Break", 1: "Forward", 2: "Reverse", 3: "Forward-Turn-Left", 4: "Forward-Turn-Right", 5: "Reverse-Turn-Left", 6: "Reverse-Turn-Right"}
        """
        Plan:
        
        of the form (action, time)
        """
        self.plan = [
            (1, 8),
            (0, 1),
            (2, 3),
            (6, 1),
            (2, 2),
            (5, 1),
            (2, 3),
            (0, 1),
            (1, 8),
            (0, 1),
            (2, 3),
            (5, 1),
            (2, 2),
            (6, 1),
            (2, 3),
            (0, 1),
            (1, 8),
            (0, 1)
        ]

    def send_signal(self, action_code, time_to_execute):
        arduino.write(bytes(f"{action_code}", "utf-8"))
        print(arduino.readline())
        time.sleep(time_to_execute)

    def execute_plan(self):
        for action_code, time_to_execute in self.plan:
            print(f"Executing: {self.actions[action_code]}")
            self.send_signal(action_code, time_to_execute)


robo_pirate_bot = Bot()
robo_pirate_bot.execute_plan()