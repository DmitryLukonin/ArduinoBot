using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Web;

namespace ArduinoBot.Helpers
{
    public static class MvcHelper
    {
        public static string GuidToBase64(Guid guid)
        {
            return Convert.ToBase64String(guid.ToByteArray()).Replace("/", "-").Replace("+", "_").Replace("=", "");
        }

        public static Guid Base64ToGuid(string base64)
        {
            Guid guid;
            base64 = base64.Replace("-", "/").Replace("_", "+") + "==";

            try
            {
                guid = new Guid(Convert.FromBase64String(base64));
            }
            catch (Exception ex)
            {
                throw new Exception("Bad Base64 conversion to GUID", ex);
            }

            return guid;
        }


        public static string GetQueryString(string key)
        {
            var query = HttpContext.Current.Request.QueryString.Get(key);
            return query;
        }

        public static string GetForm(string key)
        {
            var query = HttpContext.Current.Request.Form.Get(key);
            return query;
        }

        public static string GetHeader(this HttpRequestMessage request, string key)
        {
            IEnumerable<string> keys = null;
            if (!request.Headers.TryGetValues(key, out keys))
                return null;

            return keys.First();
        }

        public static string GetCookie(string cookieName)
        {
            var cookie = HttpContext.Current.Request.Cookies.Get(cookieName);
            if (cookie != null)
                return cookie.Value;

            return null;
        }

    }
}