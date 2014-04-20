using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ArduinoBot.Models
{
    public class Response
    {
        private readonly DateTime _time;

        public long Id { get; set; }
        public string Text { get; set; }
        public Guid CommandId { get; set; }
        public DateTime Time
        {
            get { return _time; }
        }
        public string TimeString
        {
            get { return _time.ToString("MM/dd/yyyy HH:mm:ss.fff tt"); }
        }
        public bool Received { get; set; }

        public Response()
        {
            this._time = DateTime.UtcNow;
            Received = false;
        }
    }
}