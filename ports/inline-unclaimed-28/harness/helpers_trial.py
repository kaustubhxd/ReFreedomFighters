"""helpers_trial.py - shared helpers for trial specs: globals that hold objects, logged vtable slots.

Use from a specs file:  from helpers_trial import glob_obj, logged_slot, call_log_names
  glob_obj(e, gaddr, size, slots)  -> object address; also writes the pointer into the exe global at gaddr
                                      (the exe image is reset between runs by the harness).
  logged_slot(name, eax=0, argbytes=0, st0=None)  -> a handler for fake_object/fake_vtable slots.
                                      Each call is appended to the ordered call log as (name, args...).
  The "unstubbed virtual call" stop is kept for slots not listed in `slots`, so a port cannot
  silently call a method nobody modelled.
"""


def logged_slot(name, eax=0, argbytes=0, st0=None):
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(argbytes // 4))
        e.calllog.append((name,) + args)
        e.ret(eax=eax, argbytes=argbytes, st0=st0)
    return h


def glob_obj(e, gaddr, size, slots=None, nslots=None):
    o = e.fake_object('obj@%x' % gaddr, size, nslots=nslots or 0, slots=slots or {})
    e.w32(gaddr, o)
    return o
