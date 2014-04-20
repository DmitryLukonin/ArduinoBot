using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace ArduinoBot.Models
{
    public class Command
    {
        private readonly DateTime _time;


        public long Id { get; set; }

        //public string IdEncoded
        //{
        //    get { //if () return MvcHelper.GuidToBase64(Id);
        //        return Id.ToString();
        //    }
        //    set { if(!string.IsNullOrWhiteSpace(value)) Id = MvcHelper.Base64ToGuid(value); }
        //}

        [Required]
        public string Cmd { get; set; }
        public string Type { get; set; }
        public int MsExTime { get; set; }
        public int MsDelayAfterExTime { get; set; }
        public DateTime Time
        {
            get { return _time; }
        }
        public string TimeString
        {
            get { return _time.ToString("MM/dd/yyyy HH:mm:ss.fff tt"); }
        }
        public bool Received { get; set; }

        public Command()
        {
            //Id = new Guid();
            Cmd = "";
            Type = "";
            MsExTime = 0;
            MsDelayAfterExTime = 0;
            this._time = DateTime.UtcNow;
            Received = false;
        }
    }
}