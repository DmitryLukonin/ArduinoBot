using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ArduinoBot.Models
{
    public static class AppSession
    {
        public static long CommandLastId = 0;
        public static long ResponseLastId = 0;

        public static List<Command> Commands = new List<Command>();
        public static List<Response> Responses = new List<Response>();
    }
}