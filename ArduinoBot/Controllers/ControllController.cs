using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using ArduinoBot.Helpers;
using ArduinoBot.Models;

namespace ArduinoBot.Controllers
{
    public class ControllController : Controller
    {
        //
        // GET: /Controll/

        [HttpGet]
        [Authorize(Roles = "Admin")]
        public ActionResult Index()
        {

            ViewBag.Commands = AppSession.Commands;
            ViewBag.Responses = AppSession.Responses;


            var model = new Command();

            return View(model);
        }

        [Authorize]
        [HttpPost]
        public ActionResult Index(Command command)
        {


            SessionHelper.CommandAdd(command);


            return RedirectToAction("Index");
        }
    }
}
