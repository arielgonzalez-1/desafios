#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import colorama
import openai
from colorama import Fore
from dotenv import load_dotenv


def main():
    while True:
        config["prompt"] = input(f"{Fore.CYAN}\n> ")

        if config["prompt"].lower() == "exit":
            break

        completion = openai.Completion.create(
            engine=config["engine"],
            prompt=config["prompt"],
            max_tokens=config["max_tokens"],
            # logit_bias=config["logit_bias"],
            temperature=config["temperature"]
            )
    
        print( f"{Fore.WHITE}{completion.choices[0].text}" )


if __name__ == "__main__":
    load_dotenv()

    config = {
        "engine": "text-davinci-003",
        "prompt": "",
        "max_tokens": 2048,
        "temperature" : 0,
        # "logit_bias": 100,
        "api_key": os.environ.get('API_KEY')
    }

    openai.api_key = config["api_key"]

    # print( openai.Model.list() )

    main()
