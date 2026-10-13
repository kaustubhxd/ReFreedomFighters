# Copy of inline-pathfinding/harness/pfspec.py, kept here so the unclaimed-30 specs are self-contained.
"""pfspec.py - shared spec helpers for the pathfinding tree (inline-pathfinding thread)."""
import pilot
from pilot import f32

import pe_emu

STACK_HI = pe_emu.STACK_TOP
STACK_LO = pe_emu.STACK_TOP - pe_emu.STACK_SIZE
_hooked = []
RET = {}


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def sf(x):
    try:
        return f32(x)
    except OverflowError:
        return float('inf') if x > 0 else float('-inf')


def log_args(e, nargs, opts):
    """Stack arguments for the call log. A pointer to a local of the caller is logged as ('stk', bytes): frames
    differ between the exe and the port, so only the bytes the callee may read (opts['peek'][argno]) are compared."""
    if not e.calllog:
        e._pf_stk = {}
    args = []
    for k in range(nargs):
        v = e.arg32(k)
        if STACK_LO <= v < STACK_HI:
            # identity is not compared: recursive frames reuse addresses differently in the exe and the port
            n = opts.get('peek', {}).get(k, 0)
            args.append(('stk', e.rbytes(v, n).hex() if n else ''))
        else:
            args.append(v & opts.get('mask', {}).get(k, 0xffffffff))
    return args


def vtable(c, name, nslots, impl=None, argwords=None, opts=None):
    """A fake vtable (thiscall slots) that logs (name, slot, this, args) with stack pointers normalised.
    impl: {byte_off: fn(emu, raw_args) -> eax}; argwords: {byte_off: stack words}; opts: {byte_off: {'peek':..}}."""
    impl = impl or {}
    argwords = argwords or {}
    opts = opts or {}
    slots = {}
    for i in range(nslots):
        off = 4 * i

        def h(e, r, off=off):
            n = argwords.get(off, 0)
            raw = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(log_args(e, n, opts.get(off, {})))))
            f = impl.get(off)
            v = f(e, raw) if f else 0
            e.ret(eax=v or 0, argbytes=4 * n)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def hooks(emu, table):
    """Replace real exe functions by logging stubs for this case. table: {addr: (name, conv, nargs)} where conv is
    'this' (log ECX, callee pops), 'fast' (log ECX/EDX, callee pops), 'std' (callee pops) or 'cdecl'.
    Return values come from RET[addr] (int, or ('st0', float)). Every spec gen in this tree calls this (also with
    {}) so hooks never leak into another spec."""
    for a in _hooked:
        emu.unhook(a)
    _hooked.clear()
    RET.clear()
    if not table:
        return
    for addr, ent in table.items():
        name, conv, nargs = ent[:3]
        opts = ent[3] if len(ent) > 3 else {}

        def h(e, r, addr=addr, name=name, conv=conv, nargs=nargs, opts=opts):
            args = log_args(e, nargs, opts)
            regs = ()
            if conv == 'this':
                regs = (e.reg('ecx'),)
            elif conv == 'fast':
                regs = (e.reg('ecx'), e.reg('edx'))
            regs = tuple('stk' if STACK_LO <= v < STACK_HI else v for v in regs)
            e.calllog.append((name, regs, tuple(args)))
            for k, n in opts.get('fill', {}).items():
                # deterministic output, derived from the call number and the callee
                seed = (addr * 2654435761 + len(e.calllog) * 40503) & 0xffffffff
                e.wbytes(e.arg32(k), bytes(((seed >> (8 * (i & 3))) + i * 37) & 0xff for i in range(n)))
            v = RET.get(addr, 0)
            if 'impl' in opts:
                v = opts['impl'](e, [e.arg32(k) for k in range(nargs)])
            pop = 0 if conv == 'cdecl' else 4 * nargs
            if isinstance(v, tuple):
                e.ret(argbytes=pop, st0=v[1])
            else:
                e.ret(eax=v, argbytes=pop)
        emu.hook(addr, h)
        _hooked.append(addr)


def reporter(c, hook_p=0.7):
    """g_pDebug at 0x700390 (vtable +0x20 -> reporter, reporter vtable +0x2c cdecl log) and the assert hook 0x7003b0."""
    e = c.emu
    rep = e.alloc(16)

    def log(em, r):
        em.calllog.append(('report', em.arg32(0), em.arg32(1)))
        em.ret(argbytes=0)
    rvt = e.fake_vtable('reporter', 0x20, {0x2c: log})
    e.w32(rep, rvt)
    dbg = e.alloc(16)
    e.w32(dbg, e.logging_vtable('g_pDebug', 0x10, impl={0x20: lambda em, a: (rep, None)}, argwords={0x20: 2}))
    e.w32(0x700390, dbg)
    if c.rng.random() < hook_p:
        def brk(em, r):
            em.calllog.append(('assert-hook',))
            em.ret()
        e.w32(0x7003b0, e.stub_fn('assert-hook', brk))
    else:
        e.w32(0x7003b0, 0)


# Clear the hooks before every run, so a spec without hooks never sees another spec's stubs.
_orig_one_run = pilot.one_run


_ZERO = bytes(0x400000)
# exe globals the specs of this tree write (address, bytes)
GLOBALS = [(0x70039c, 4), (0x700390, 4), (0x7003b0, 4), (0x70038c, 4), (0x72580c, 4), (0x6e9000, 1),
           (0x701b5c, 1), (0x701b5d, 1), (0x6ffa28, 2), (0x701b58, 1), (0x701b4d, 1)]


def _one_run(emu, spec, *a, **k):
    hooks(emu, {})
    # The pilot clears only the heap the last run allocated; an out-of-bounds write past it (exe or port) would
    # survive into the next run. Clear the first 4 MB of heap first so both runs start from the same memory.
    emu.mu.mem_write(pilot.HEAP_BASE, _ZERO)
    # Specs set exe globals with host writes, which the image-dirty hook does not see: put them back first.
    for ga, gn in GLOBALS:
        emu.mu.mem_write(ga, bytes(emu.image[ga - emu.base:ga - emu.base + gn]))
    return _orig_one_run(emu, spec, *a, **k)


pilot.one_run = _one_run


# ret='ax': a u16 return; only AX is defined (the upper half of EAX is left over).
_orig_run = pilot.Pilot.run


def _run(self, addr, abi, args, ret, max_insns=2000000):
    if ret == 'ax':
        out = _orig_run(self, addr, abi, args, 'eax', max_insns=max_insns)
        out['eax'] &= 0xffff
        return out
    return _orig_run(self, addr, abi, args, ret, max_insns=max_insns)


pilot.Pilot.run = _run


def allocator(c, cap=0x200000):
    """g_pAllocator at 0x70038c (vtable +8 = alloc(size), thiscall): fresh fake-heap memory filled with 0x5a."""
    e = c.emu

    def new(em, rr):
        n = em.arg32(0)
        em.calllog.append(('alloc', n))
        em.ret(eax=em.alloc(n, 16, 0x5a) if n < cap else 0, argbytes=4)
    a = e.alloc(16)
    e.w32(a, e.fake_vtable('allocator', 4, {8: new}))
    e.w32(0x70038c, a)
