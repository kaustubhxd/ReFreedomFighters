"""specs_s1049.py - unclaimed-04 batch 49 (docs/20-unclaimed-04.md): 0x54ed70 (thiscall, ret 8) and 0x4d1d70 (stdcall, ret 4).
0x54ed70: the first argument's vtable slot 0 (stdcall, three arguments) returns an HRESULT; a negative value gives 0.
Otherwise, when the low byte of the second argument is non-zero, this's vtable slot 0x10 is called; the result is 1.
0x4d1d70: helper 0x4d1cf0 (hooked by address, GUESS) returns an object or 0. An object gives its dword at +0x10. Zero goes
through the manager at global 0x700390 (slot 0x20, thiscall, logged) and the logger's slot 0x2c (cdecl, logged).
Stubs are logging vtables (GUESS: the interface and log slots are not identified)."""
from pilot import S


def _setup54(c):
    e = c.emu
    this_vt = e.logging_vtable('this54', 0x10 // 4 + 1, argwords={0x10: 0})
    e.this_vt = this_vt


def _args54(c):
    e = c.emu
    e.qi_hr = c.rng.choice([0, 1, 0x7fffffff, 0x80000000, 0x80004002, c.rng.getrandbits(32)])
    obj_vt = e.logging_vtable('qi', 1, impl={0: lambda em, a: (em.qi_hr, None)}, argwords={0: 3})
    obj = e.alloc(0x20, 4)
    e.w32(obj, obj_vt)
    this = e.alloc(0x40, 4)
    e.w32(this, e.this_vt)
    e.wbytes(this + 4, bytes(c.rng.getrandbits(8) for _ in range(4)))
    # the flag is the low byte: 0x100 has a zero low byte and skips the slot 0x10 call
    flag = c.rng.choice([0, 1, 0x100, 0xff, c.rng.getrandbits(32)])
    return [this, obj, flag]


def _setup4d(c):
    e = c.emu

    def hook_lookup(em, r):
        em.calllog.append(('4d1cf0', 0, 0, (em.arg32(0),)))
        em.ret(eax=getattr(em, 'lookup_ret', 0), argbytes=4)

    e.hook(0x4d1cf0, hook_lookup)

    def log_cdecl(em, r):
        # cdecl: the caller pops the two arguments, so no bytes are popped here
        em.calllog.append(('logger2c', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    logger_vt = e.fake_vtable('logger', 0x2c // 4 + 1, slots={0x2c: log_cdecl})
    logger = e.alloc(0x40, 4)
    e.w32(logger, logger_vt)
    e.logger_obj = logger
    mgr_vt = e.logging_vtable('mgr', 0x20 // 4 + 1, impl={0x20: lambda em, a: (em.logger_obj, None)},
                              argwords={0x20: 2})
    mgr = e.alloc(0x40, 4)
    e.w32(mgr, mgr_vt)
    e.w32(0x700390, mgr)


def _args4d(c):
    e = c.emu
    if c.rng.random() < 0.5:
        p = e.alloc(0x20, 4)
        e.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
        e.lookup_ret = p
    else:
        e.lookup_ret = 0
    return [c.rng.getrandbits(32)]


S(0x54ed70, 'unknown::thiscall_qi_slot10 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args54,
  setup=_setup54, note='unclaimed-04 batch 49; QueryInterface-style and slot 0x10 stubs are logging vtables (GUESS)')

S(0x4d1d70, 'unknown::stdcall_4d1cf0_log (unknown) stdcall', 'stdcall', None, ret='eax', gen=_args4d,
  setup=_setup4d, note='unclaimed-04 batch 49; 0x4d1cf0 hooked by address; manager and logger are logging vtables (GUESS)')
